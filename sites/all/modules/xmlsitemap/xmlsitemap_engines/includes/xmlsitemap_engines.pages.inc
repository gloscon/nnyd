<?php
// $Id: xmlsitemap_engines.pages.inc,v 1.1.2.1 2008/11/28 16:48:51 kiam Exp $

/**
 * @file
 * Menu pages for xmlsitemap_engines.
 */

/**
 * @addtogroup xmlsitemap
 * @{
 */

/*****************************************************************************
 * Menu callbaks / Form builders.
 ****************************************************************************/

/**
 * Menu callback; display the verification page.
 */
function xmlsitemap_engines_verify($engine) {
  switch ($engine) {
    case 'google':
      print '<html>'."\n";
      print '  <head>'."\n";
      print '    <title>Hello, Google!</title>'."\n";
      print '  </head>'."\n";
      print '  <body>'."\n";
      print '    <p>Hello, Google!</p>'."\n";
      print '  </body>'."\n";
      print '</html>'."\n";
      break;
    case 'yahoo':
      print variable_get('xmlsitemap_engines_yahoo_verify_string', '');
      break;
    case 'live':
      print '<?xml version="1.0"?>'."\n";
      print "<users>\n";
      print '    <user>'. variable_get('xmlsitemap_engines_live_verify_string', '') ."</user>\n";
      print "</users>\n";
      break;
  }
  drupal_page_footer();
  exit;
}

/**
 * @} End of "addtogroup xmlsitemap".
 */
 