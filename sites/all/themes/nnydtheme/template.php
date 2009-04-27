<?php

 function nnydtheme_login_box() {
  global $user;

  if (!$user->uid) {
    $output .= drupal_get_form('nnyd_login_block');
    return $output;
  }
  else {
    $output = '<p>You are logged in as <b>' . $user->name . '</b>';
    $output .= '&nbsp;'.'&nbsp;'.'&nbsp;'.'&nbsp;'.'&nbsp;' . l(t('Logout'), 'logout', array('title' => t('Logout'))) . '<br/>';
    $output .= l(t('Manage Account'), 'user/' . $user->uid . '', array('title' => t('manage my account')));
    $output .= '</p>';
    return $output;
  }
}


/* Checks to see if we're in the admin section */
function nnydtheme_is_admin() {
  if (((arg(0) == 'admin') || (arg(0) == 'administer') || (arg(0) == 'user') ) && (user_access('access administration pages'))) {
    return true;
  }
}

function nnyd_login_block() {
  $form = array(
    '#action' => url($_GET['q'], array('query' => drupal_get_destination())),
    '#id' => 'user-login-form',
    '#validate' => user_login_default_validators(),
    '#submit' => array('user_login_submit'),
  );
  $form['name'] = array('#type' => 'textfield',
    '#title' => t('Username'),
    '#maxlength' => USERNAME_MAX_LENGTH,
    '#size' => 15,
    '#required' => TRUE,
  );
  $form['pass'] = array('#type' => 'password',
    '#title' => t('Password'),
    '#maxlength' => 60,
    '#size' => 15,
    '#required' => TRUE,
  );
  $form['submit'] = array('#type' => 'submit',
    '#value' => t('Sign In'),
  );
  $items = array();

  if (variable_get('user_register', 1)) {
    $items[] = l(t('Sign Up'), 'user/register', array('title' => t('Create a new user account.')));
  }
  $items[] = l(t('Reset Password???'), 'user/password', array('title' => t('Request new password via e-mail.')));
  $form['links'] = array('#value' => theme('item_list', $items));
  return $form;
}



/*function nnydtheme_search_box() {
  $form[$form_id] = array(
    '#title' => t('Search this site'),
    '#type' => 'textfield',
    '#size' => 15,
    '#default_value' => '',
    '#attributes' => array('title' => t('Enter the terms you wish to search for.')),
  );
  $form['submit'] = array('#type' => 'submit', '#value' => t('Search'));
  $form['#submit'][] = 'search_box_form_submit';
  $form['#validate'][] = 'search_box_form_validate';
print 'hi';
  return $form;
}*/

/*function search_form_alter(&$form, $form_state, $form_id) {
    switch ($form_id) {
      case 'search_theme_form':
        $form['search_theme_form']['#title'] = t('Search'); 
	 $form['search_theme_form']['#size'] = 50;   
        break;
    }
  }*/
function nnydtheme_theme() {
  return array(
    // The form ID.
    'search_theme_form' => array(
      // Forms always take the form argument.
      'arguments' => array('form' => NULL),
    ),

	'drupal_add_js' => array(
      // Forms always take the form argument.
      'arguments' => array('theme' => nnydtheme),
    )
  );
}

 function nnydtheme_search_theme_form($form) {
   
    // this line deactivate the 'search this site' label - you can change/delete this
  //  unset($form['search_theme_form']['#title']);
   
    // remove the submit button - you can change/delete this
   // unset($form['submit']);
   
    // Change the size of the search box (you can change the value '25 to whatever you want) - you can change/delete this
    $form['search_theme_form']['#size'] = 25;
   
    // Set a default value in the search box, you can change 'search' to whatever you want - you can change/delete this
    //$form['search_theme_form']['#value'] = 'Search';
    // Additionnaly, hide the text when editing - you can change/delete this
    // Remember to change the value 'search' here too if you change it in the previous line
    $form['search_theme_form']['#attributes'] = array('onblur' => "if (this.value == '') {this.value = 'search';}", 'onfocus' => "if (this.value == 'search') {this.value = '';}" );
   
    // Don't change this
    $output .= drupal_render($form);
    return $output;
}

/*function nnydtheme_drupal_add_js($data = NULL, $type = 'module', $scope = 'header', $defer = FALSE, $cache = TRUE, $preprocess = TRUE) {
  static $javascript = array();
print 'jsjsjs';
  if (isset($data)) {

    // Add jquery.js and drupal.js, as well as the basePath setting, the
    // first time a Javascript file is added.
    if (empty($javascript)) {
      $javascript['header'] = array(
        'core' => array(
          'misc/jquery.js' => array('cache' => TRUE, 'defer' => FALSE, 'preprocess' => TRUE),
          'misc/drupal.js' => array('cache' => TRUE, 'defer' => FALSE, 'preprocess' => TRUE),
        ),
        'module' => array(),
        'theme' => array(),
        'setting' => array(
          array('basePath' => base_path()),
        ),
        'inline' => array(),
      );
    }

    if (isset($scope) && !isset($javascript[$scope])) {
      $javascript[$scope] = array('core' => array(), 'module' => array(), 'theme' => array(), 'setting' => array(), 'inline' => array());
    }

    if (isset($type) && isset($scope) && !isset($javascript[$scope][$type])) {
      $javascript[$scope][$type] = array();
    }

    switch ($type) {
      case 'setting':
        $javascript[$scope][$type][] = $data;
        break;
      case 'inline':
        $javascript[$scope][$type][] = array('code' => $data, 'defer' => $defer);
        break;
      default:
        // If cache is FALSE, don't preprocess the JS file.
        $javascript[$scope][$type][$data] = array('cache' => $cache, 'defer' => $defer, 'preprocess' => (!$cache ? FALSE : $preprocess));
    }
  }

  if (isset($scope)) {

    if (isset($javascript[$scope])) {
      return $javascript[$scope];
    }
    else {
      return array();
    }
  }
  else {
    return $javascript;
  }
}*/





/*!
 * Dynamic display block preprocess functions
 * Copyright (c) 2008 - 2009 P. Blaauw All rights reserved.
 * Version 1.1 (11-FEB-2009)
 * Licenced under GPL license
 * http://www.gnu.org/licenses/gpl.html
 */

 /**
 * Override or insert variables into the ddblock_cycle_block_content templates.
 *   Used to convert variables from view_fields to slider_items template variables
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 * 
 */
function nnydtheme_preprocess_ddblock_cycle_block_content(&$vars) {
  if ($vars['output_type'] == 'view_fields') {
    $content = array();
    // Add slider_items for the template 
    // If you use the devel module uncomment the following line to see the theme variables
    // dsm($vars['settings']['view_name']);  
     //dsm($vars['content'][0]);
    // If you don't use the devel module uncomment the following line to see the theme variables
    // drupal_set_message('<pre>' . var_export($vars['settings']['view_name'], true) . '</pre>');
     //drupal_set_message('<pre>' . var_export($vars['content'][0], true) . '</pre>');
    if ($vars['settings']['view_name'] == 'nnydbuzz_items') {
      foreach ($vars['content'] as $key1 => $result) {
        // add slide_image variable 
        if (isset($result->node_data_field_pager_item_text_field_image_fid)) {
          // get image id
          $fid = $result->node_data_field_pager_item_text_field_image_fid;
          // get path to image
          $filepath = db_result(db_query("SELECT filepath FROM {files} WHERE fid = %d", $fid));
          //  use imagecache (imagecache, preset_name, file_path, alt, title, array of attributes)
          if (module_exists('imagecache') && is_array(imagecache_presets()) && $vars['imgcache_slide'] <> '<none>'){
            $slider_items[$key1]['slide_image'] = 
            theme('imagecache', 
                  $vars['imgcache_slide'], 
                  $filepath,
                  $result->node_title);
          }
          else {          
            $slider_items[$key1]['slide_image'] = 
              '<img src="' . base_path() . $filepath . 
              '" alt="' . $result->node_title . 
              '"/>';     
          }          
        }
        // add slide_text variable
        if (isset($result->node_data_field_pager_item_text_field_slide_text_value)) {
          $slider_items[$key1]['slide_text'] =  $result->node_data_field_pager_item_text_field_slide_text_value;
        }
        // add slide_title variable
        if (isset($result->node_title)) {
          $slider_items[$key1]['slide_title'] =  $result->node_title;
        }
        // add slide_read_more variable and slide_node variable
        if (isset($result->nid)) {
          $slider_items[$key1]['slide_read_more'] =  l('More', 'node/' . $result->nid);
          $slider_items[$key1]['slide_node'] =  'node/' . $result->nid;
        }
      }
      $vars['slider_items'] = $slider_items;  
    }    
  }
}  
/**
 * Override or insert variables into the ddblock_cycle_pager_content templates.
 *   Used to convert variables from view_fields  to pager_items template variables
 *  Only used for custom pager items
 *
 * @param $vars
 *   An array of variables to pass to the theme template.
 *
 */
function nnydtheme_preprocess_ddblock_cycle_pager_content(&$vars) {
  if (($vars['output_type'] == 'view_fields') && ($vars['pager_settings']['pager'] == 'custom-pager')){
    $content = array();
    // Add pager_items for the template 
    // If you use the devel module uncomment the following lines to see the theme variables
    // dsm($vars['pager_settings']['view_name']);     
    // dsm($vars['content'][0]);     
    // If you don't use the devel module uncomment the following lines to see the theme variables
     //drupal_set_message('<pre>' . var_export($vars['pager_settings'], true) . '</pre>');
     //drupal_set_message('<pre>' . var_export($vars['content'][0], true) . '</pre>');
    if ($vars['pager_settings']['view_name'] == 'nnydbuzz_items') {
      foreach ($vars['content'] as $key1 => $result) {
        // add pager_item_image variable
        if (isset($result->node_data_field_pager_item_text_field_image_fid)) {
          $fid = $result->node_data_field_pager_item_text_field_image_fid;
          $filepath = db_result(db_query("SELECT filepath FROM {files} WHERE fid = %d", $fid));
          //  use imagecache (imagecache, preset_name, file_path, alt, title, array of attributes)
          if (module_exists('imagecache') && 
              is_array(imagecache_presets()) && 
              $vars['imgcache_pager_item'] <> '<none>'){
            $pager_items[$key1]['image'] = 
              theme('imagecache', 
                    $vars['pager_settings']['imgcache_pager_item'],              
                    $filepath,
                    $result->node_data_field_pager_item_text_field_pager_item_text_value);
          }
          else {          
            $pager_items[$key1]['image'] = 
              '<img src="' . base_path() . $filepath . 
              '" alt="' . $result->node_data_field_pager_item_text_field_pager_item_text_value . 
              '"/>';     
          }          
        }
        // add pager_item _text variable
        if (isset($result->node_data_field_pager_item_text_field_pager_item_text_value)) {
          $pager_items[$key1]['text'] =  $result->node_data_field_pager_item_text_field_pager_item_text_value;
        }
      }
    }
    $vars['pager_items'] = $pager_items;
  }    
}


//function phptemplate_nodeasblock($node) {


  // Get an HTML representation of the themed node.
  // node_view($node, $teaser = FALSE, $page = FALSE, $links = TRUE)
//  $content = node_view($nodeasblock, TRUE, FALSE, TRUE);
 
  // If the user has permissions to edit the node, then add a link.
  /*if (node_access('update', $node)) {
    $content .= '<div class="nodeasblock-edit-link">'. l('['. t('edit') .']', 'node/'. $node->nid .'/edit', array("title" => t("Edit"))) .'</div>';
  } */

 
//  return $content;

/* return array(
    'subject' => l($node->title, 'node/' . $node->nid),
    'content' => _phptemplate_callback('nodeasblock', array('node' => $node)),
  );*/

//}



/*function nnydtheme_views_more($url) {
  return "<div class='more-link'>" . l(t('View All...'), $url) . "</div>";
}*/



/* The embedded flash displaying the youtube video.
 */
function nnydtheme_emvideo_youtube_flash($embed, $width, $height, $autoplay, $options = array()) {
  static $count;
  if ($embed) {
    $related = isset($options['related']) ? $options['related'] : variable_get('emvideo_youtube_show_related_videos', 0);
    $related = "rel=$related";
    $autoplay = isset($options['autoplay']) ? $options['autoplay'] : $autoplay;
    $autoplay_value = $autoplay ? '&autoplay=1' : '';
    $show_colors = isset($options['show_colors']) ? $options['show_colors'] : variable_get('emvideo_youtube_show_colors', FALSE);
    if ($show_colors) {
      $color1 = isset($options['color1']) ? $options['color1'] : variable_get('emvideo_youtube_colors_color1', emvideo_YOUTUBE_COLOR1_DEFAULT);
      $color2 = isset($options['color2']) ? $options['color2'] : variable_get('emvideo_youtube_colors_color2', emvideo_YOUTUBE_COLOR2_DEFAULT);
      $colors='&color1=0x'. emvideo_youtube_convert_color($color1) .'&color2=0x'. emvideo_youtube_convert_color($color2);
    }
    $border = isset($options['border']) ? $options['border'] : variable_get('emvideo_youtube_show_border', FALSE);
    $border = $border ? '&border=1' : '';
    $enablejsapi = isset($options['enablejsapi']) ? $options['enablejsapi'] : variable_get('emvideo_youtube_enablejsapi', TRUE);
    $enablejsapi = $enablejsapi ? '&enablejsapi=1&playerapiid=ytplayer' : '';
    $allowScriptAcess = $enablejsapi ? 'always' : 'sameDomain';
    $id = isset($options['id']) ? $options['id'] : 'video-cck-youtube-flash-'. (++$count);
    $div_id = isset($options['div_id']) ? $options['div_id'] : 'video-cck-youtube-flash-wrapper-'. $count;
    $url = "http://www.youtube.com/v/$embed&amp;$related$autoplay_value$colors$border$enablejsap";
    if (variable_get('emfield_swfobject', FALSE) && (module_exists('swfobject_api') || variable_get('emfield_swfobject_location', ''))) {
      if (module_exists('swfobject_api')) {
        $params['width'] = $width;
        $params['height'] = $height;
        $params['div_id'] = $id;
        $output .= theme('swfobject_api', $url, $params, $vars, $id);
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
        <div id="$div_id"><object type="application/x-shockwave-flash" height="$height" width="$width" data="$url" id="$id">
          <param name="movie" value="$url" />
          <param name="allowScriptAcess" value="sameDomain"/>
          <param name="quality" value="best"/>
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

function nnydtheme_menu_item_link($link) {

	if (empty($link['localized_options'])) {
    $link['localized_options'] = array();
  }

  if($link['has_children']==1){
		if($link['plid']==0){
			 $varattr = array('attributes'=>array('class'=>'head headmain'),$link['localized_options']);
		}else{
		   $varattr = array('attributes'=>array('class'=>'head'),$link['localized_options']);
		}
	}else{
	$varattr = $link['localized_options'];
	}

	return l($link['title'], $link['href'],$varattr);

}

function nnydtheme_menu_item($link, $has_children, $menu = '', $in_active_trail = FALSE, $extra_class = NULL) {
  $class = ($menu ? 'expanded' : ($has_children ? 'collapsed' : 'leaf'));
  if (!empty($extra_class)) {
    $class .= ' '. $extra_class;
  }
  if ($in_active_trail) {
    $class .= ' active-trail';
  }
	
  return '<li class="'. $class .'">'. $link . $menu ."</li>\n";
}


function nnydtheme_links($links, $attributes = array('class' => 'links')) {
  global $language;
  $output = '';
  
  if($attributes['class'] == 'primaryLinks') {
   $attributes['class'] = 'primaryLinks links';
  }
  if (count($links) > 0) {
    $output = '<ul'. drupal_attributes($attributes) .'>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = $key;

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class .= ' first';
      }
      if ($i == $num_links) {
        $class .= ' last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
          && (empty($link['language']) || $link['language']->language == $language->language)) {
        $class .= ' active';
      }
      $output .= '<li'. drupal_attributes(array('class' => $class)) .'>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      else if (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span'. $span_attributes .'>'. $link['title'] .'</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}


function nnydtheme_event_upcoming_item($node, $types = array()) {

  $custom_node = node_load($node->nid);
  $datestart=convert_datetimetemp($node->event_start);
    
  $output = '<div class="reventtitle">'.l($node->title,"node/$node->nid", array('attributes' => array('title' => $node->title))).'</div>';
  $output .= '<div class="eventdate">'.date("F,j,Y",$datestart).'</div>';
  $output .= '<div class="content">'. $custom_node->body.'</div>';

  $output .= '<div class="eventmorelink">'.l("more...",'node/'.$custom_node->nid).'</div>';  


$output .= '<br>'.'</br>';
//$output .='<div class="eventmorelink1">'.l("View All...",'upcomingevent/all').'</div>';    

return $output;
}

function convert_datetimetemp($str) {
 


  list($date, $time) = explode(' ', $str);
  list($year, $month, $day) = explode('-', $date);
  //list($hour, $minute, $second) = explode(':', $time);
  
  $timestamp = mktime(0,0,0,intval($month), intval($day), intval($year));
  
  return $timestamp;
}


function nnydtheme_event_more_link($path) {
  return '<div class="eventmorelink1">'. l(t('View All...'), 'upcomingevents/all', array('attributes' => array('title' => t('View All...')))) .'</div>';
}


