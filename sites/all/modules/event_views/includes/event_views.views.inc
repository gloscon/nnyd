<?php

 /**
  * hook_views_handlers -- implementation
  */
  function event_views_views_handlers() {
	  return array(
	  	'info' => array(
			'path' => drupal_get_path('module','event_views'). '/includes',
		),
		'handlers' => array(
			'event_views_handler_field_date_iso' => array(
				'parent' => 'views_handler_field',
			),
			'event_views_handler_filter_date_iso' => array(
				'parent' => 'views_handler_filter',
			),
		),
	  );
  } // function event_views_views_handlers



/**
 *  Implementation of hook_views_data()
 *  Expose event fields and filters to the views module.
 */
function event_views_views_data() {
        // okay let's define a group :V
        $data['event']['table']['group']  = t('Event');

		//'og_views_handler_filter_og_group_nid' => array('parent' => 'views_handler_filter_numeric',


        // define a base table ????
        $data['event']['table']['base'] = t('Event');

        // define joins...????
        $data['event']['table']['join'] = array(
                'node' => array(
                        'handler' => 'views_join',
                        'left_table' => 'node',
                        'left_field' => 'nid',
                        'right_field' => 'nid',
                        'field' => 'nid' )
        );

        // okay define fields ...???
        $data['event']['event_start'] = array(
                'title' => t('Event start'),
                'help' => t('The event start datetime.'),
                'field' => array(
                        'handler' => 'event_views_handler_field_date_iso', // we cannot do this, need to make a new class
            /* old: views_handler_field_date*/
                        'click sortable' => TRUE,
                ),
                 /* arguments are going to be much more complicated? */
                 //'argument' => array(),
                'filter' => array(
                        'handler' => 'event_views_handler_filter_date_iso',
            /* old: views_handler_filter_date */
                ),
                'sort' => array(
                        'handler' => 'views_handler_sort',
                ),
        );

        $data['event']['event_end'] = array(
                'title' => t('Event end'),
                'help' => t('The event end datetime.'),
                'field' => array(
                        'handler' => 'event_views_handler_field_date_iso',
            /* old: views_handler_field_date */
                        'click sortable' => TRUE,
                ),
                'filter' => array(
                        'handler' => 'event_views_handler_filter_date_iso',
            /* event_views_handler_filter_date_iso */
                ),
                'sort' => array(
                        'handler' => 'views_handler_sort',
                ),
        );

        return $data;
} // function event_views_views_data

