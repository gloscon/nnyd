<?php
// $Id: youtube.inc,v 1.1.2.15 2009/01/04 18:17:24 alexua Exp $

/**
 * @file
 *   This include processes youtube.com media files for use by emfield.module.
 */

define('EMVIDEO_YOUTUBE_MAIN_URL', 'http://www.youtube.com/');
define('EMVIDEO_YOUTUBE_API_INFO', 'http://youtube.com/dev');
define('EMVIDEO_YOUTUBE_API_APPLICATION_URL', 'http://www.youtube.com/my_profile_dev');
define('EMVIDEO_YOUTUBE_REST_ENDPOINT', 'http://www.youtube.com/api2_rest');
define('EMVIDEO_YOUTUBE_COLOR1_DEFAULT', '#FFFFFF');
define('EMVIDEO_YOUTUBE_COLOR2_DEFAULT', '#CCCCCC');

/**
 * hook emvideo_PROVIDER_info
 * this returns information relevant to a specific 3rd party video provider
 * @return
 *   an array of strings requested by various admin and other forms
 *   'name' => the translated name of the provider
 *   'url' => the url to the main page for the provider
 *   'settings_description' => a description of the provider that will be posted in the admin settings form
 *   'supported_features' => an array of rows describing the state of certain supported features by the provider.
 *      These will be rendered in a table, with the columns being 'Feature', 'Supported', 'Notes'.
 */
function emvideo_youtube_info() {
  $features = array(
    array(t('Autoplay'), t('Yes'), ''),
    array(t('RSS Attachment'), t('Yes'), ''),
    array(t('Show related videos'), t('Yes'), t('This is embedded in the video itself when enabled; currently not available with other providers. Set the feature above.')),
    array(t('Thumbnails'), t('Yes'), t('')),
    array(t('Custom player colors'), t('Yes'), t("You may customize the player's skin by choosing your own colors, and/or border in that setting field set.")),
    array(t('Full screen mode'), t('Yes'), t('You may customize the player to enable or disable full screen playback. Full screen mode is enabled by default.')),
  );
  return array(
    'provider' => 'youtube',
    'name' => t('YouTube'),
    'url' => EMVIDEO_YOUTUBE_MAIN_URL,
    'settings_description' => t('These settings specifically affect videos displayed from <a href="@youtube" target="_blank">YouTube</a>. You can learn more about its <a href="@api" target="_blank">API</a> here.', array('@youtube' => EMVIDEO_YOUTUBE_MAIN_URL, '@api' => EMVIDEO_YOUTUBE_API_INFO)),
    'supported_features' => $features,
  );
}

/**
 * hook emvideo_PROVIDER_settings
 * this should return a subform to be added to the emvideo_settings() admin settings page.
 * note that a form field will already be provided, at $form['PROVIDER'] (such as $form['youtube'])
 * so if you want specific provider settings within that field, you can add the elements to that form field.
 */
function emvideo_youtube_settings() {
  $form['youtube']['emvideo_youtube_show_related_videos'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show related videos'),
    '#default_value' => variable_get('emvideo_youtube_show_related_videos', 0),
    '#description' => t('If checked, then when playing a video from YouTube, users may hover over the video to see thumbnails & links to related videos.'),
  );
  $form['youtube']['api'] = array(
    '#type' => 'fieldset',
    '#title' => t('YouTube API'),
    '#description' => t('The API is no longer required. However, there may be future features requiring it (such as the ability to display otherwise private videos). You will first need to apply for an API Developer Key from the <a href="@youtube" target="_blank">YouTube Developer Profile page</a>. Note that you do not need this key to display YouTube videos or their thumbnails.', array('@youtube' => EMVIDEO_YOUTUBE_API_APPLICATION_URL)),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['youtube']['api']['emvideo_youtube_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('YouTube API Key'),
    '#default_value' => variable_get('emvideo_youtube_api_key', ''),
    '#description' => t('Please enter your YouTube Developer Key here.'),
  );
  $form['youtube']['api']['emvideo_youtube_api_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('YouTube API Secret'),
    '#default_value' => variable_get('emvideo_youtube_api_secret', ''),
    '#description' => t('If you have a secret for the YouTube API, enter it here.'),
  );
  $form['youtube']['colors'] = array(
    '#type' => 'fieldset',
    '#title' => t('Embedded Video Player Colors'),
    '#description' => t('If allowed, these two colors, in hexidecimal form (#RRGGBB), will be used to skin the YouTube player.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['youtube']['colors']['emvideo_youtube_show_colors'] = array(
    '#type' => 'checkbox',
    '#title' => t('Override player colors'),
    '#default_value' => variable_get('emvideo_youtube_show_colors', FALSE),
  );
  $form['youtube']['colors']['emvideo_youtube_show_border'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display border around player'),
    '#default_value' => variable_get('emvideo_youtube_show_border', FALSE),
  );
  $form['youtube']['colors']['emvideo_youtube_colors_color1'] = array(
    '#type' => 'textfield',
    '#title' => t('Color 1'),
    '#default_value' => variable_get('emvideo_youtube_colors_color1', EMVIDEO_YOUTUBE_COLOR1_DEFAULT),
  );
  $form['youtube']['colors']['emvideo_youtube_colors_color2'] = array(
    '#type' => 'textfield',
    '#title' => t('Color 2'),
    '#default_value' => variable_get('emvideo_youtube_colors_color2', EMVIDEO_YOUTUBE_COLOR2_DEFAULT),
  );
  $form['youtube']['player_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Embedded video player options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['youtube']['player_options']['emvideo_youtube_full_screen'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow fullscreen'),
    '#default_value' => variable_get('emvideo_youtube_full_screen', 1),
    '#description' => t('Allow users to view video using the entire computer screen.'),
  );

  if (module_exists('colorpicker')) {
    $form['youtube']['colors']['emvideo_youtube_colors_color1']['#type'] = 'colorpicker_textfield';
    $form['youtube']['colors']['emvideo_youtube_colors_color1']['#colorpicker'] = 'colorpicker_1';
    $form['youtube']['colors']['emvideo_youtube_colors_color2']['#type'] = 'colorpicker_textfield';
    $form['youtube']['colors']['emvideo_youtube_colors_color2']['#colorpicker'] = 'colorpicker_2';
    $form['youtube']['colors']['colorpicker_1'] = array(
      '#type' => 'colorpicker',
      '#title' => t('Color 1 picker'),
      '#description' => t('Click in this textfield to start picking your color'),
    );
    $form['youtube']['colors']['colorpicker_2'] = array(
      '#type' => 'colorpicker',
      '#title' => t('Color 2 picker'),
      '#description' => t('Click in this textfield to start picking your color'),
    );
  }
  else {
    $form['youtube']['colors']['#description'] .= ' '. t('The <a href="@colorpicker">Colorpicker module</a>, if active, gives an easy way to select these colors.', array('@colorpicker' => 'http://drupal.org/project/colorpicker'));
  }
  return $form;
}

/**
 * hook emfield_PROVIDER_data
 *
 * provides an array to be serialised and made available with $item elsewhere
 */
function emvideo_youtube_data($field, $item) {
  $data = array();
  // create some 'field' version control
  $data['emvideo_youtube_version'] = 1;

  // be nice to make this an array for changing media:thumbnail?
  $data['thumbnail']['url'] = 'http://img.youtube.com/vi/'. $item['value'] .'/0.jpg';

  // gather info about the item
  // RSS / MRSS feeds with the item would have enough info
  // alternative try getting the minimum from an http get
  $url = 'http://youtube.com/v/'. $item['value'];
  $response = emfield_request_header('youtube', $url);

  if ($response->code == 200) {
    // probably shouldn't give the 303 path
    $data['flash']['url'] = $url;
    $data['flash']['size'] = $response->headers['Content-Length'];
    $data['flash']['mime'] = $response->headers['Content-Type'];
  }

  return $data;
}

/**
 *
 */
function emvideo_youtube_rss($item, $teaser = NULL) {
  if ($item['value']) {
    if (!empty($item['data']['emvideo_youtube_data_version']) && $item['data']['emvideo_youtube_data_version'] >= 1) {
      $data = $item['data'];
    }
    else {
      $data = emvideo_youtube_data(NULL, $item);
    }

    $file = array();
    if (is_array($data['flash'])) {
      $file['filepath'] = $data['flash']['url'];
      $file['filesize'] = $data['flash']['size'];
      $file['filemime'] = $data['flash']['mime'];
    }
    $file['thumbnail']['filepath'] = $data['thumbnail']['url'];

    return $file;
  }
}

/**
 * this is a wrapper for emvideo_request_xml that includes youtube's api key
 */
function emvideo_youtube_request($method, $args = array(), $cached = TRUE) {
  $args['dev_id'] = trim(variable_get('emvideo_youtube_api_key', ''));
  $args['method'] = $method;

  // if we've got a secret sign the arguments
  // TODO: doesn't seem to matter
//  if ($secret = trim(variable_get('emvideo_youtube_api_secret', ''))) {
//    $args['api_sig'] = md5($secret . $arghash);
//  }

  $request = module_invoke('emfield', 'request_xml', 'youtube', EMVIDEO_YOUTUBE_REST_ENDPOINT, $args, $cached);
  return $request;
}

/**
 * hook emvideo_PROVIDER_extract
 * this is called to extract the video code from a pasted URL or embed code.
 * @param $embed
 *   an optional string with the pasted URL or embed code
 * @return
 *   either an array of regex expressions to be tested, or a string with the video code to be used
 *   if the hook tests the code itself, it should return either the string of the video code (if matched), or an empty array.
 *   otherwise, the calling function will handle testing the embed code against each regex string in the returned array.
 */
function emvideo_youtube_extract($embed = '') {
  // src="http://www.youtube.com/v/nvbQQnvxXDk"
  // http://youtube.com/watch?v=nvbQQnvxXDk
  // http://www.youtube.com/watch?v=YzFCA-xUc8w&feature=dir
  return array(
    '@youtube\.com/v/([^"\&]+)@i',
    '@youtube\.com/watch\?v=([^"\&]+)@i',
     '@youtube\.com/\?v=([^"\&]+)@i',
  );
}

/**
 * hook emvideo_PROVIDER_embedded_link($video_code)
 * returns a link to view the video at the provider's site
 *  @param $video_code
 *    the string containing the video to watch
 *  @return
 *    a string containing the URL to view the video at the original provider's site
 */
function emvideo_youtube_embedded_link($video_code) {
  return 'http://www.youtube.com/watch?v='. $video_code;
}

function emvideo_youtube_convert_color($color = NULL) {
  if ($color{0} == '#') {
    return drupal_substr($color, 1);
  }

  return $color;
}

/**
 * The embedded flash displaying the youtube video.
 */
function theme_emvideo_youtube_flash($embed, $width, $height, $autoplay, $options = array()) {
  static $count;
  $output = '';
  if ($embed) {
    $fullscreen = variable_get('emvideo_youtube_full_screen', 1);
    $fullscreen_value = $fullscreen ? "true" : "false";
    $fs = $fullscreen ? "&amp;fs=$fullscreen" : "";
    $related = isset($options['related']) ? $options['related'] : variable_get('emvideo_youtube_show_related_videos', 0);
    $related = "rel=$related";
    $autoplay = isset($options['autoplay']) ? $options['autoplay'] : $autoplay;
    $autoplay_value = $autoplay ? '&autoplay=1' : '';
    $show_colors = isset($options['show_colors']) ? $options['show_colors'] : variable_get('emvideo_youtube_show_colors', FALSE);
    $colors = '';
    if ($show_colors) {
      $color1 = isset($options['color1']) ? $options['color1'] : variable_get('emvideo_youtube_colors_color1', emvideo_YOUTUBE_COLOR1_DEFAULT);
      $color2 = isset($options['color2']) ? $options['color2'] : variable_get('emvideo_youtube_colors_color2', emvideo_YOUTUBE_COLOR2_DEFAULT);
      $colors='&color1=0x'. emvideo_youtube_convert_color($color1) .'&color2=0x'. emvideo_youtube_convert_color($color2);
    }
    $border = isset($options['border']) ? $options['border'] : variable_get('emvideo_youtube_show_border', FALSE);
    $border = $border ? '&border=1' : '';
    $enablejsapi = isset($options['enablejsapi']) ? $options['enablejsapi'] : variable_get('emvideo_youtube_enablejsapi', TRUE);
    $enablejsapi = $enablejsapi ? '&enablejsapi=1&playerapiid=ytplayer' : '';
    $id = isset($options['id']) ? $options['id'] : 'video-cck-youtube-flash-'. (++$count);
    $div_id = isset($options['div_id']) ? $options['div_id'] : 'video-cck-youtube-flash-wrapper-'. $count;
    $url = "http://www.youtube.com/v/$embed&amp;$related$autoplay_value$colors$border$enablejsapi$fs";
    if (variable_get('emfield_swfobject', FALSE) && (module_exists('swfobject_api') || variable_get('emfield_swfobject_location', ''))) {
      if (module_exists('swfobject_api')) {
        $params['width'] = $width;
        $params['height'] = $height;
        $params['div_id'] = $id;
        $params['allowFullScreen'] = $fullscreen_value;
        $output .= theme('swfobject_api', $url, $params, $options, $id);
      }
      else {
        drupal_add_js(variable_get('emfield_swfobject_location', ''));
        $output .= <<<FLASH
          <div id="$div_id">
            Sorry, you need to install flash to see this content.
          </div>
          <script language="JavaScript" type="text/javascript">
            var so = new SWFObject("$url", "$id", "$width", "$height", "7");
            so.write("$div_id");
          </script>
FLASH;
      }
    }
    else {
      $output .= <<<FLASH
        <div id="$div_id"><object type="application/x-shockwave-flash" height="$height" width="$width" data="$url" id="$id" allowFullScreen="$fullscreen_value">
          <param name="movie" value="$url" />
          <param name="allowScriptAcess" value="sameDomain"/>
          <param name="quality" value="best"/>
          <param name="allowFullScreen" value="$fullscreen_value"/>
          <param name="bgcolor" value="#FFFFFF"/>
          <param name="scale" value="noScale"/>
          <param name="salign" value="TL"/>
          <param name="FlashVars" value="playerMode=embedded" />
          <param name="wmode" value="transparent" />
        </object></div>
FLASH;
    }
  }
  return $output;
}

/**
 * hook emvideo_PROVIDER_thumbnail
 * returns the external url for a thumbnail of a specific video
 * TODO: make the args: ($embed, $field, $item), with $field/$item provided if we need it, but otherwise simplifying things
 *  @param $field
 *    the field of the requesting node
 *  @param $item
 *    the actual content of the field from the requesting node
 *  @return
 *    a URL pointing to the thumbnail
 */
function emvideo_youtube_thumbnail($field, $item, $formatter, $node, $width, $height) {
  $youtube_id = $item['value'];
  // Old code to grab thumbnail via API.
//$request = emvideo_youtube_request('youtube.videos.get_details', array('video_id' => $youtube_id));
//$tn = $request['THUMBNAIL_URL'][0];

  // if we have a large thumbnail size, then get the larger version available.
  if ($width > 130 || $height > 97) {
    $tn = "http://img.youtube.com/vi/$youtube_id/0.jpg";
  }
  else {
    // youtube offers 3 thumbnails. select one randomly.
    $rand = rand(0, 2) + 1;
    $tn = "http://img.youtube.com/vi/$youtube_id/$rand.jpg";
  }

  return $tn;
}

/**
 * hook emvideo_PROVIDER_video
 * this actually displays the full/normal-sized video we want, usually on the default page view
 *  @param $embed
 *    the video code for the video to embed
 *  @param $width
 *    the width to display the video
 *  @param $height
 *    the height to display the video
 *  @param $field
 *    the field info from the requesting node
 *  @param $item
 *    the actual content from the field
 *  @return
 *    the html of the embedded video
 */
function emvideo_youtube_video($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $output = theme('emvideo_youtube_flash', $embed, $width, $height, $autoplay);
  return $output;
}

/**
 * hook emvideo_PROVIDER_video
 * this actually displays the preview-sized video we want, commonly for the teaser
 *  @param $embed
 *    the video code for the video to embed
 *  @param $width
 *    the width to display the video
 *  @param $height
 *    the height to display the video
 *  @param $field
 *    the field info from the requesting node
 *  @param $item
 *    the actual content from the field
 *  @return
 *    the html of the embedded video
 */
function emvideo_youtube_preview($embed, $width, $height, $field, $item, &$node, $autoplay) {
  $output = theme('emvideo_youtube_flash', $embed, $width, $height, $autoplay);
  return $output;
}

/**
 * Implementation of hook_emfield_subtheme.
 */
function emvideo_youtube_emfield_subtheme() {
    return array(
        'emvideo_youtube_flash'  => array(
            'arguments' => array('embed' => NULL, 'width' => NULL, 'height' => NULL, 'autoplay' => NULL),
            'file' => 'providers/youtube.inc'
        )
    );
}
