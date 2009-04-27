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
		</div> <!--headerfull ends-->		
	<div class="navbar">		
	<!--<ul>
          <?php if ($site_slogan) { ?><li class="slogan"><?php print $site_slogan ?></li><?php } ?>	 
	</ul>-->
	    <!--  <?php print theme('links', $primary_links); ?>-->
		<?php print $header;?>
	</div> <!-- navbar ends-->

	

  <!--  <div class="header-line">headerline</div> -->
<div class="maincontent">
    <?php if ($mission != ""): ?>
      <div class="subheader"> 
      <?php print $mission; ?>
      </div> <!-- subheader ends-->
    <?php endif; ?> 

		<div class="left">
     <!--   <?php print $breadcrumb ?>-->
      <!-- <?php if ($title) {?><h2 class="title"><?php print $title ?></h2> <?php };?>-->
        <?php if ($tabs) {?><div class="tabs"><?php print $tabs ?></div> <?php };?>
        <?php print $help ?>
        <?php print $messages ?>
        <?php print $content; ?>
        <?php print $feed_icons; ?>
		</div><!--left ends-->	

     		<div class="right">
         		<?php print $right ?>
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

