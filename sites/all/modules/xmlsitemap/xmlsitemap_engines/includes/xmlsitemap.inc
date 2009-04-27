<?php
// $Id: xmlsitemap.inc,v 1.1.2.1 2008/11/29 19:25:15 kiam Exp $

/**
 * @file
 * Generic handlers for xmlsitemap_engines.
 */

/**
 * @addtogroup xmlsitemap
 * @{
 */

/*****************************************************************************
 * Drupal hooks.
 ****************************************************************************/

/**
 * Implementation of hook_xmlsitemap_engines().
 */
function xmlsitemap_engines_xmlsitemap_engines($op, $type = NULL) {
  switch ($op) {
    case 'form':
      // Google fields.
      $form['google'] = array(
        '#type' => 'fieldset',
        '#title' => t('Google'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['google']['xmlsitemap_engines_google_submit'] = array(
        '#type' => 'checkbox',
        '#title' => t('Submit site map to Google.'),
        '#default_value' => variable_get('xmlsitemap_engines_google_submit', FALSE),
      );
      $form['google']['xmlsitemap_engines_google_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Submission URL'),
        '#default_value' => variable_get('xmlsitemap_engines_google_url', 'http://www.google.com/webmasters/tools/ping?sitemap='. xmlsitemap_url('sitemap.xml', drupal_lookup_path('alias', 'sitemap.xml') ? drupal_lookup_path('alias', 'sitemap.xml') : NULL, NULL, NULL, TRUE)),
        '#description' => t('The URL to submit the site map to.'),
      );
      $form['google']['xmlsitemap_engines_google_verify'] = array(
        '#type' => 'textfield',
        '#title' => t('Verification link'),
        '#default_value' => variable_get('xmlsitemap_engines_google_verify', ''),
        '#description' => t('In order to show statistics, Google will ask you to verify that you control this site by creating a file with a certain name. Enter that name here and the XML Sitemap module will create a path to that file name. This will only work if you have clean URLs enabled.'),
      );
      // Yahoo! fields.
      $form['yahoo'] = array(
        '#type' => 'fieldset',
        '#title' => t('Yahoo!'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['yahoo']['xmlsitemap_engines_yahoo_submit'] = array(
        '#type' => 'checkbox',
        '#title' => t('Submit site map to Yahoo!'),
        '#default_value' => variable_get('xmlsitemap_engines_yahoo_submit', FALSE),
      );
      $form['yahoo']['xmlsitemap_engines_yahoo_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Submission URL'),
        '#default_value' => variable_get('xmlsitemap_engines_yahoo_url', 'http://search.yahooapis.com/SiteExplorerService/V1/ping?sitemap='. xmlsitemap_url('sitemap.xml', drupal_lookup_path('alias', 'sitemap.xml') ? drupal_lookup_path('alias', 'sitemap.xml') : NULL, NULL, NULL, TRUE)),
        '#description' => t('The URL to submit the site map to.'),
      );
      $form['yahoo']['xmlsitemap_engines_yahoo_verify'] = array(
        '#type' => 'textfield',
        '#title' => t('Verification link'),
        '#default_value' => variable_get('xmlsitemap_engines_yahoo_verify', ''),
        '#description' => t('Before allowing you to view additional information, Yahoo! will ask you to verify that you control this site by creating a file with a certain name. Enter that name here, and XML Sitemap will create a path to that file name. This will only work if you have clean URLs enabled.'),
      );
      $form['yahoo']['xmlsitemap_engines_yahoo_verify_string'] = array(
        '#type' => 'textfield',
        '#title' => t('Authentication key'),
        '#default_value' => variable_get('xmlsitemap_engines_yahoo_verify_string', ''),
        '#description' => t('Yahoo! will ask you to put an authentication key in the verification file.'),
      );
      // Ask.com fields.
      $form['ask'] = array(
        '#type' => 'fieldset',
        '#title' => t('Ask.com'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['ask']['xmlsitemap_engines_ask_submit'] = array(
        '#type' => 'checkbox',
        '#title' => t('Submit site map to Ask.com.'),
        '#default_value' => variable_get('xmlsitemap_engines_ask_submit', FALSE),
      );
      $form['ask']['xmlsitemap_engines_ask_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Submission URL'),
        '#default_value' => variable_get('xmlsitemap_engines_ask_url', 'http://submissions.ask.com/ping?sitemap='. xmlsitemap_url('sitemap.xml', drupal_lookup_path('alias', 'sitemap.xml') ? drupal_lookup_path('alias', 'sitemap.xml') : NULL, NULL, NULL, TRUE)),
        '#description' => t('The URL to submit the site map to.'),
      );
      // Windows Live fields.
      $form['live'] = array(
        '#type' => 'fieldset',
        '#title' => t('Windows Live'),
        '#collapsible' => TRUE,
        '#collapsed' => TRUE,
      );
      $form['live']['xmlsitemap_engines_live_submit'] = array(
        '#type' => 'checkbox',
        '#title' => t('Submit site map to Windows Live.'),
        '#default_value' => variable_get('xmlsitemap_engines_live_submit', FALSE),
      );
      $form['live']['xmlsitemap_engines_live_url'] = array(
        '#type' => 'textfield',
        '#title' => t('Submission URL'),
        '#default_value' => variable_get('xmlsitemap_engines_live_url', 'http://webmaster.live.com/ping.aspx?siteMap='. xmlsitemap_url('sitemap.xml', drupal_lookup_path('alias', 'sitemap.xml') ? drupal_lookup_path('alias', 'sitemap.xml') : NULL, NULL, NULL, TRUE)),
        '#description' => t('The URL to submit the site map to.'),
      );
      $form['live']['xmlsitemap_engines_live_verify'] = array(
        '#type' => 'textfield',
        '#title' => t('Authentication file'),
        '#default_value' => variable_get('xmlsitemap_engines_live_verify', 'LiveSearchSiteAuth.xml'),
        '#description' => t('Before allowing you to view additional information, Windows Live will ask you to verify that you control this site by creating a file with a certain name. Enter that name here, and XML Sitemap will create a path to that file name. This will only work if you have clean URLs enabled.'),
      );
      $form['live']['xmlsitemap_engines_live_verify_string'] = array(
        '#type' => 'textfield',
        '#title' => t('Authentication tag'),
        '#default_value' => variable_get('xmlsitemap_engines_live_verify_string', ''),
        '#description' => t('Windows Live will give you an authentication tag.'),
      );
      return $form;
    case 'ping':
      $sitemap_alias = NULL;
      if ($alias = drupal_lookup_path('alias', 'sitemap.xml')) {
        $sitemap_alias = $alias;
      }
      $sitemap_url = xmlsitemap_url('sitemap.xml', $sitemap_alias, NULL, NULL, TRUE);
      // Submit the site map to Google.
      if (variable_get('xmlsitemap_engines_google_submit', FALSE)) {
        xmlsitemap_engines_submit_sitemap('Google', 'xmlsitemap_engines_google_url', 'http://www.google.com/webmasters/tools/ping?sitemap='. $sitemap_url);
      }
      // Submit the site map to Yahoo!.
      if (variable_get('xmlsitemap_engines_yahoo_submit', FALSE)) {
        xmlsitemap_engines_submit_sitemap('Yahoo!', 'xmlsitemap_engines_yahoo_url', 'http://search.yahooapis.com/SiteExplorerService/V1/ping?sitemap='. $sitemap_url);
      }
      // Submit the site map to Ask.com.
      if (variable_get('xmlsitemap_engines_ask_submit', FALSE)) {
        xmlsitemap_engines_submit_sitemap('Ask.com', 'xmlsitemap_engines_ask_url', 'http://submissions.ask.com/ping?sitemap='. $sitemap_url);
      }
      // Submit the site map to Windows Live.
      if (variable_get('xmlsitemap_engines_live_submit', FALSE)) {
        xmlsitemap_engines_submit_sitemap('Windows Live', 'xmlsitemap_engines_live_url', 'http://webmaster.live.com/ping.aspx?siteMap='. $sitemap_url);
      }
      break;
    case 'access':
      if (strpos($_SERVER['HTTP_USER_AGENT'], 'Googlebot') !== FALSE) {
        return t('!sitemap downloaded by Google.', array('!sitemap' => $type));
      }
      break;
  }
}

/**
 * @} End of "addtogroup xmlsitemap".
 */
