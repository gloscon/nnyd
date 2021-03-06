<?php
// $Id: panels_views.admin.inc,v 1.1 2008/08/06 00:24:46 merlinofchaos Exp $

/**
 * @file panels_views.module
 *
 * Provides views as panels content, configurable by the administrator.
 * Each view provided as panel content must be configured in advance,
 * but once configured, building panels with views is a little bit simpler.
 */

function panels_views_admin_page() {
  $form['panels_views_all_views'] = array(
    '#type' => 'checkbox',
    '#title' => t('Make all views available as panes'),
    '#description' => t("If checked, all views will be made available as content panes to be added to content types. If not checked, only Views that have a 'Panel pane' display will be available as content panes."),
    '#default_value' => variable_get('panels_views_all_views', FALSE),
  );

  return system_settings_form($form);

}