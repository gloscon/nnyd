<?php
// $Id: xmlsitemap.pages.inc,v 1.1.2.4 2008/12/18 02:21:27 kiam Exp $

/**
 * @file
 * Menu pages for xmlsitemap.module.
 */

/**
 * @addtogroup xmlsitemap
 * @{
 */

/*****************************************************************************
 * Menu callbacks / form builders, submit/validate functions.
 ****************************************************************************/

/**
 * Menu callback; display the site map.
 * @param $chunk
 *  An integer specifying which chunk of the site map is being requested.
 *  If not set and there is more than one chunk, display the site map index.
 */
function xmlsitemap_output($chunk = NULL) {
  if (variable_get('xmlsitemap_update', FALSE)) {
    _xmlsitemap_update();
  }
  drupal_set_header('Content-type: text/xml; charset=utf-8');
  $chunk_size = variable_get('xmlsitemap_chunk_size', 50000);
  $xml = _xmlsitemap_xml();
  if (isset($chunk)) {
    $links_count = _xmlsitemap_link_count();
    if ($chunk < $links_count / $chunk_size) {
      _xmlsitemap_output_chunk($chunk);
    }
    elseif ($chunk < $links_count / $chunk_size + count($xml)) {
      $previous = (integer) ($links_count / $chunk_size + 1);
      print $xml[$chunk - $previous];
    }
    else {
      drupal_not_found();
    }
  }
  else {
    if ($links_count > $chunk_size || count($xml) > 0) {
      _xmlsitemap_output_index();
    }
    else {
      _xmlsitemap_output_chunk();
    }
  }
  drupal_page_footer();
  exit;
}

/**
 * Menu callback; get XSL style sheet.
 */
function xmlsitemap_xsl() {
  drupal_set_header('Content-Type: application/xml; charset=utf-8');
  include drupal_get_path('module', 'xmlsitemap') .'/gss/gss.php';
  drupal_page_footer();
  exit;
}

/**
 * @} End of "addtogroup xmlsitemap".
 */
