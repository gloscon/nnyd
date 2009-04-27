<?php
// $Id: odeo.inc,v 1.1.4.7 2008/12/16 16:12:57 aaron Exp $

/**
 * @file
 * This include processes Odeo audio files for use by emaudio.module.
 */

define('EMAUDIO_ODEO_MAIN_URL', 'http://odeo.com/');
/**
 * Implementation of hook emaudio_odeo_info().
 *
 * This returns information relevant to a specific 3rd party audio provider.
 *
 * @return
 *   An array of strings requested by various admin and other forms.
 *   'name' => The translated name of the provider.
 *   'url' => The url to the main page for the provider.
 *   'settings_description' => A description of the provider that will be posted in the admin settings form.
 *   'supported_features' => An array of rows describing the state of certain supported features by the provider.
 *      These will be rendered in a table, with the columns being 'Feature', 'Supported', 'Notes'.
 */
function emaudio_odeo_info() {
  $features = array(
    array(t('Autoplay'), t('No'), ''),
    array(t('RSS Attachment'), t('No'), ''),
    array(t('Thumbnails'), t('No'), t('')),
  );
  return array(
    'provider' => 'odeo',
    'name' => t('odeo'),
    'url' => EMAUDIO_ODEO_MAIN_URL,
    'settings_description' => t('These settings specifically affect audio podcasts displayed from <a href="@odeo" target="_blank">odeo</a>.', array('@odeo' => EMAUDIO_ODEO_MAIN_URL)),
    'supported_features' => $features,
  );
}

/**
 * Implementation of hook emaudio_odeo_settings().
 *
 * This should return a subform to be added to the emaudio_settings() admin settings page.
 * Note that a form field will already be provided, at $form['odeo'] (such as $form['podomatic']).
 * So if you want specific provider settings within that field, you can add the elements to that form field.
 */
function emaudio_odeo_settings() {
  $form = array();

  return $form;
}

/**
 * Implementation of hook emaudio_odeo_extract().
 *
 * This is called to extract the video code from a pasted URL or embed code.
 *
 * @param $embed
 *   An optional string with the pasted URL or embed code.
 * @return
 *   Either an array of regex expressions to be tested, or a string with the
 *   audio code to be used. If the hook tests the code itself, it should return
 *   either the string of the audio code (if matched), or an empty array.
 *   Otherwise, the calling function will handle testing the embed code against
 *   each regex string in the returned array.
 */
function emaudio_odeo_extract($embed = '') {
  return array(
    '@odeo\.com/audio/([0-9]+)/@i',
    '@href="http://odeo.com/audio/([0-9]+)/@i',
  );
}

/**
 * The embedded flash displaying the odeo audio.
 *
 * Default width is 322, height is 54.
 */
function theme_emaudio_odeo_flash($embed, $width, $height, $autoplay) {
  if ($embed) {
    /*
    if ($autoplay) {
      $autoplay_value = '&autostart=1';
    }
    */

    $output .= "
      <object classid=\"clsid:d27cdb6e-ae6d-11cf-96b8-444553540000\" codebase=\"http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,47,0\"width=\"$width\" height=\"$height\" id=\"wimpy\" align=\"center\">
      <param name=\"quality\" value=\"high\" />
      <param name=\"width\" value=\"$width\" />
      <param name=\"height\" value=\"$height\" />
      <param name=\"name\" value=\"odeo_player_black\" />
      <param name=\"allowScriptAccess\" value=\"always\" />
      <param name=\"wmode\" value=\"transparent\" />
      <embed src=\"http://odeo.com/flash/audio_player_black.swf\"
      quality=\"high\" width=\"322\" height=\"54\"
      name=\"odeo_player_black\" align=\"middle\"
      allowScriptAccess=\"always\" wmode=\"transparent\"
      type=\"application/x-shockwave-flash\" flashvars=\"type=audio&id=". $embed ."\" pluginspage=\"http://www.macromedia.com/go/getflashplayer\" />
      </object>
    \n";
  }

  return $output;
}

/**
 * Implementation of hook emaudio_odeo_thumbnail().
 *
 * Returns the external url for a thumbnail of a specific audio.
 * TODO: make the args: ($embed, $field, $item), with $field/$item provided if we need it, but otherwise simplifying things.
 *
 * @param $field
 *   The field of the requesting node.
 * @param $item
 *   The actual content of the field from the requesting node.
 * @return
 *   A URL pointing to the thumbnail.
 */
function emaudio_odeo_thumbnail($field, $item, $formatter, $node, $width, $height) {
  return $tn;
}

/**
 * Implementation of hook emaudio_odeo_audio().
 *
 * This actually displays the full/normal-sized video we want, usually on the default page view.
 *
 * @param $embed
 *   The video code for the audio to embed.
 * @param $width
 *   The width to display the audio.
 * @param $height
 *   The height to display the audio.
 * @param $field
 *   The field info from the requesting node.
 * @param $item
 *   The actual content from the field.
 * @return
 *   The html of the embedded audio.
 */
function emaudio_odeo_audio($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $output = theme('emaudio_odeo_flash', $embed, $width, $height, $autoplay);

  return $output;
}

/**
 * Implementation of hook emaudio_odeo_preview().
 *
 * This actually displays the preview-sized video we want, commonly for the teaser.
 *
 * @param $embed
 *   The video code for the audio to embed.
 * @param $width
 *   The width to display the audio.
 * @param $height
 *   The height to display the audio.
 * @param $field
 *   The field info from the requesting node.
 * @param $item
 *   The actual content from the field.
 * @return
 *   The html of the embedded audio.
 */
function emaudio_odeo_preview($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $output = theme('emaudio_odeo_flash', $embed, $width, $height, $autoplay);

  return $output;
}

/**
 * Implementation of hook_emfield_subtheme.
 */
function emaudio_odeo_emfield_subtheme() {
  return array (
    'emaudio_odeo_flash'  => array(
            'arguments' => array('embed' => NULL, 'width' => NULL, 'height' => NULL, 'autoplay' => NULL),
            'file' => 'providers/odeo.inc'
        )
    );
}
