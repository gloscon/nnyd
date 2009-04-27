<?php

class event_views_handler_field_date_iso extends views_handler_field
{
    function render($values)
    {   
        $value = $values->{$this->field_alias};

        return $value ? event_format_date($value, 'small') : theme('views_nodate');
    } // function render

} // class event_views_handler_field_date_iso

