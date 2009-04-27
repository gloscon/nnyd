<?php
// $Id: xmlsitemap.admin.inc,v 1.1.2.3 2008/11/29 19:25:14 kiam Exp $

/**
 * @file
 * Administration pages for xmlsitemap.module.
 */

/**
 * @addtogroup xmlsitemap
 * @{
 */

/*****************************************************************************
 * Menu callbacks / form builders, submit/validate functions.
 ****************************************************************************/

/**
 * Menu callback; return search engine settings form.
 */
function xmlsitemap_settings_engines() {
  $form['submission'] = array(
    '#type' => 'fieldset',
    '#title' => t('Submission settings'),
    '#collapsible' => TRUE,
  );
  $form['submission']['xmlsitemap_submit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Submit site map when updated.'),
    '#default_value' => variable_get('xmlsitemap_submit', FALSE),
    '#description' => t('If enabled, search engines will be notified of changes to the site map each time it is updated.'),
  );
  $form['submission']['xmlsitemap_cron_submit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Submit site map on cron run.'),
    '#default_value' => variable_get('xmlsitemap_cron_submit', FALSE),
    '#description' => t('If enabled, search engines will be notified of changes to the site map each time cron is run.'),
  );
  $form['submission']['xmlsitemap_log_access'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log access.'),
    '#default_value' => variable_get('xmlsitemap_log_access', FALSE),
    '#description' => t('If enabled, a watchdog entry will be made each time the site map is accessed, containing information about the requestor.'),
  );
  module_load_all_includes('inc', 'includes/xmlsitemap');
  $form = array_merge($form, module_invoke_all('xmlsitemap_engines', 'form'));
  $form = system_settings_form($form);
  array_unshift($form['#submit'], 'xmlsitemap_settings_engines_submit');
  return $form;
}

/**
 * Submit search engine settings form.
 */
function xmlsitemap_settings_engines_submit($form, &$form_state) {
  if ($form_state['values']['xmlsitemap_root']) {
    $form_state['values']['xmlsitemap_submit'] = FALSE;
    $form_state['values']['xmlsitemap_log_access'] = FALSE;
  }
  menu_rebuild();
}

/**
 * Menu callback; return site map settings form.
 */
function xmlsitemap_settings_sitemap() {
  $form['xmlsitemap_chunk_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Chunk size'),
    '#default_value' => variable_get('xmlsitemap_chunk_size', 50000),
    '#size' => 10,
    '#maxlength' => 5,
    '#description' => t('This is the number of links to include in one site map. Values can range between 1 and 50,000. If the total number of links exceeds the chunk size, multiple site maps will be generated.'),
    '#weight' => -1,
  );
  $form['xmlsitemap_front_page_priority'] = array(
    '#type' => 'select',
    '#title' => t('Front page priority'),
    '#default_value' => variable_get('xmlsitemap_front_page_priority', 1),
    '#options' => xmlsitemap_priority_options(),
    '#description' => t('This is the absolute priority for the front page.'),
    '#weight' => -1,
  );
  $form = system_settings_form($form);
  $form['#submit'][] = 'xmlsitemap_update_sitemap';
  return $form;
}

/**
 * Validate site map settings form.
 */
function xmlsitemap_settings_sitemap_validate($form, &$form_state) {
  if ($form_state['values']['xmlsitemap_chunk_size'] > 50000) {
    form_set_error('xmlsitemap_chunk_size', t('Cannot send more than 50,000 links at one time.'));
  }
}

/**
 * @} End of "addtogroup xmlsitemap".
 */
