<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language ?>" xml:lang="<?php print $language->language ?>">

  <head>
    <title><?php print $head_title ?></title>
    <meta http-equiv="Content-Style-Type" content="text/css" />
	<?php print $head ?>
	<?php print $styles ?>
	<?php print $scripts ?>
	<script type="text/javascript"><?php /* Needed to avoid Flash of Unstyle Content in IE */ ?> </script>
  </head>


<body>
	<div class="main">
		<div class="headerfull">

			<div class="header_left">
			    <div class="logo">
			     <?php if ($logo):?>
		     <?php print '<a href="'. check_url($front_page) .'" title="'. $site_title .'"><img src="'. check_url($logo) .'" alt="'. $site_title .'" id="logo" /></a>'; ?>
			<?php endif; ?>
			</div> <!--logo ends-->	
			   
			</div> <!-- header_left-->
			
			<div class="header_center">
				<div class="userlogin_button"></div>
			 <?php print nnydtheme_login_box(); ?>
			</div> <!--header_center ends-->		
			
			<div class="header_right">
       			   <?php print $search_box; ?>
			</div> <!--header_right ends-->		
			
	<div class="navbar">		

	<!--<ul>
          <?php if ($site_slogan) { ?><li class="slogan"><?php print $site_slogan ?></li><?php } ?>	 
	</ul>-->
	      <!--<?php print theme('links', $primary_links, array('class' => 'primaryLinks')); ?>-->
<?php print $header;?>
	</div> <!-- navbar ends-->
</div> <!--headerfull ends-->	
	
<div class="headerimageswrap"><?php print $headerimages ;?>



</div><!-- headerimageswrap ends-->


<!--<div class="threeicons">

<?php global $user;

$result=db_query("SELECT node.nid AS nid FROM node node WHERE node.type='join_nnyd_form' AND node.status <> 0 AND node.uid=$user->uid");

$output = db_result($result);?>

<?php $pathsemi = drupal_get_path(theme,'nnydtheme');?>

<?php $temppath = $pathsemi.'/images';?>
 
<?php 
if($output) {
$output1 .= '<div class="threeicons1">'.theme('image',$temppath.'/fade_nnyd.jpg', $attributes = NULL, $getsize = TRUE).'</div>';
print $output1;
}
else{
  $output1 .='<div class="threeicons1">'.l(theme('image',$temppath.'/newjoin_nnyd.jpg', $attributes = NULL, $getsize = TRUE),'node/add/join-nnyd-form',array('html' => TRUE)).'</div>';

print $output1;
}
?>

<?php print '<div class="threeicons1">'.l(theme('image',$temppath.'/article.jpg', $attributes = NULL, $getsize = TRUE),'article/all',array('html' => TRUE)).'</div>';?>

<?php print '<div class="threeicons1">'.l(theme('image',$temppath.'/blog.jpg', $attributes = NULL, $getsize = TRUE),'blog',array('html' => TRUE)).'</div>';?>

<?php print '<div class="threeicons1">'.l(theme('image',$temppath.'/forum.jpg', $attributes = NULL, $getsize = TRUE),'forum',array('html' => TRUE)).'</div>';?>

<?php print '<div class="threeicons1">'.l(theme('image',$temppath.'/newdonate.jpg', $attributes = NULL, $getsize = TRUE),'content/page/paypal-donate-here',array('html' => TRUE)).'</div>';?>

</div> three icons ends-->

  <!--  <div class="header-line">headerline</div> -->
<div class="maincontent">
    <?php if ($mission != ""): ?>
      <div class="subheader"> 
      <?php print $mission; ?>
      </div> <!-- subheader ends-->
    <?php endif; ?> 

		<div class="left">
        <?php print $breadcrumb ?>
        <?php if ($title) {?><h2 class="title"><?php print $title ?></h2> <?php };?>
        <?php if ($tabs) {?><div class="tabs"><?php print $tabs ?></div> <?php };?>
        <?php print $help ?>
        <?php print $messages ?>
        <?php print $content; ?>
        <?php print $feed_icons; ?>
		</div><!--left ends-->	

     		<div class="right">
         		<?php print $right ?>
<!--<div class="fouricons">

<?php $pathsemi = drupal_get_path(theme,'nnydtheme');?>

<?php $path = $pathsemi.'/images';?>

<?php print '<div class="fouricons1">'.l(theme('image',$path.'/newsletterimg.jpg',$alt = '', $title = '', $attributes = NULL, $getsize = TRUE),'node/74',array('html' => TRUE)).'</div>';?>

<?php print '<div class="fouricons2">'.l(theme('image',$path.'/tour.jpg',$alt = '', $title = '', $attributes = NULL, $getsize = TRUE),'videos/all',array('html' => TRUE)).'</div>';?>

<?php print '<div class="fouricons3">'.l(theme('image',$path.'/video.jpg',$alt = '', $title = '', $attributes = NULL, $getsize = TRUE),'videos/all',array('html' => TRUE)).'</div>';?>

<?php print '<div class="fouricons4">'.l(theme('image',$path.'/photo.jpg',$alt = '', $title = '', $attributes = NULL, $getsize = TRUE),'images/all',array('html' => TRUE)).'</div>';?>
<?php// endif;?>

</div>  four icons ends-->  

		</div> <!--right ends-->
</div> <!--main content ends-->
	
	<div class="footer">
		<span class="footermes">
      <?php print $footer_message ?></span><!--footermes ends-->
   <!--   <?php print theme('links', $secondary_links); ?>-->

<!--for adding separator between secondary links--><div class="seclinks">
<?php
            if (isset($secondary_links)) :
            $sec_links=array();
            foreach ($secondary_links as $link) {
            $sec_links[]= l($link['title'], 
              $link['href'], 
              $link['attributes'], 
              $link['query'],
              $link['fragment'], 
              FALSE, 
              $link['html']);
             }  
            $output = implode("&nbsp;|&nbsp;",$sec_links);
              print $output;
            endif; 
?>						</div><!-- seclinks ends-->
<div class="feeds">
<?php $pathsemi = drupal_get_path(theme,'nnydtheme');?>

<?php $path = $pathsemi.'/images';?>

<?php print '<div class="feedsicon">'.l(theme('image',$path.'/RSS_icon.jpg',$alt = '', $title = '', $attributes = NULL, $getsize = TRUE),'rssfeeds',array('html' => TRUE)).'</div>';?>

<div class="feedsdata">
<?php print l('RSS Feeds','rssfeeds',array('html' => TRUE)); ?>
</div><!--feedsdata ends-->

</div><!--feeds ends-->
      <?php print $closure ?>
		
	</div> <!-- footer ends -->
	</div><!--main ends-->
</body>
</html>

