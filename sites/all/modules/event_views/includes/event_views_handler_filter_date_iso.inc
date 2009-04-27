<?php

class event_views_handler_filter_date_iso extends views_handler_filter
{
/*
    function options_form(&$form,$form_state)
    {
        $form['event_views_date_custom'] = array(
            '#type' => 'textfield',
            '#title' => t('Custom Date'),
            '#description' => t('Enter a custom date time in ISO format.'),
            '#default_value' => '',
            '#weight' => 5,
        );
    } */

    function operators()
    {   
        $operators = array(
            'before' => array(
                'title' => t('Before date'),
                'short' => t('<'),
                'method' => 'op_before',
                'values' => 1,
            ),
            'on' => array( 
                'title' => t('On date'),
                'short' => t('='),
                'method' => 'op_on',
                'values' => 1,
            ),
            'after' => array(
                'title' => t('After date'),
                'short' => t('>'),
                'method' => 'op_after',
                'values' => 1,
            )
        );

        return $operators;
  
    } // function operators

  function operator_options($which = 'title')
  {
    $options = array();
    foreach ($this->operators() as $id => $info)
    { 
      $options[$id] = $info[$which];
    }

    return $options;
  }


  function operator_values($values = 1)
  {
    $options = array();
    foreach ($this->operators() as $id => $info)
    { 
      if (isset($info['values']) && $info['values'] == $values)
      { 
        $options[] = $id;
      }
    }

    return $options;
  }


    function value_form(&$form,$form_state)
    {
        $time_options = array( 'today' => t('Today'), 'yesterday' => t('Yesterday'), 'lastweek' => t('Last Week'), 'tomorrow' => t('Tomorrow'), 'nextweek' => t('Next Week') , /*'custom' => t('Custom Date')*/ );

        $form['value'] = array(
            '#type' => 'select',
            '#title' => t('Value'),
            '#description' => t('Select the event timeframe to compare to'),
            '#default_value' => 'today',
            '#options' => $time_options,
        );

    } // function value_form


    function value_form_validate(&$form,$form_state) { } // function value_form_validate


    function do_date_op($date,$op)
    {
        $dt_str = '';
        switch($op)
        {
            case 'tomorrow':
                $date->modify("+1 day");
            break;
            case 'yesterday':
                $date->modify("-1 day");
            case 'lastweek':
                $date->modify("-7 day");
            break;
            case 'nextweek':
                $date->modify("+7 day");
            break;
        }

        return date_format($date,'o-m-d');
    } // function do_date_op

    function op_before($field)
    {   
        $my_date = date_create();
        $this->value = $this->do_date_op($my_date,$this->value);
        $this->query->add_where($this->options['group'],"%s < '%s'",$field,$this->value);
    } // function op_before


    function op_after($field)
    {   
        $my_date = date_create();
        $this->value = $this->do_date_op($my_date,$this->value);
        $this->query->add_where($this->options['group'],"%s > '%s'",$field,$this->value);
    } // function op_after


    // thank goodness postgresql and mysql functions match up for CAST() :V
    function op_on($field)
    {   
        $my_date = date_create();
        $this->value = $this->do_date_op($my_date,$this->value);
        $this->query->add_where($this->options['group'],"cast(%s as date) = '%s'",$field,$this->value);
    } // function op_before


    function query()
    {   
        $this->ensure_my_table();
        $field = "$this->table_alias.$this->real_field";

        $info = $this->operators();
        if (!empty($info[$this->operator]['method']))
            $this->{$info[$this->operator]['method']}($field);

    } // function query



} // class event_views_handler_filter_date_iso

