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
		<div class="header">
			<div class="top_info">
				<div class="top_info_right">
                 <?php print internet_center_login_box(); ?>
				</div>		
				<div class="top_info_left">
					<p>Today is: <b><?php print date('j F, Y') ?></b><br />
					Check todays <a href="#">hot topics</a> or <a href="#">new pictures</a></p>
				</div>
			</div>
			<div class="logo">
        <?php if ($site_name) : ?>
            <?php if ($site_name) { ?><h1 class='site-name'><a href="<?php print $base_path ?>" title="<?php print t('Home') ?>"><?php print $site_name ?></a></h1><?php } ?>
        <?php endif;?>
			</div>
		</div>
		
		<div class="bar">
			<ul>
        <?php if ($site_slogan) { ?><li class="slogan"><?php print $site_slogan ?></li><?php } ?>	 
			</ul>
      <?php print theme('links', $primary_links); ?>
		</div>

    <div class="header-line"></div> 

    <?php if ($mission != ""): ?>
      <div class="subheader"> 
      <?php print $mission; ?>
      </div> 
    <?php endif; ?> 

		<div class="left<?php if (internet_center_is_admin()) print ' left_admin_view';?>">
			<div class="left_articles">
        <?php print $breadcrumb ?>
        <?php if ($title) {?><h2 class="title"><?php print $title ?></h2> <?php };?>
        <?php if ($tabs) {?><div class="tabs"><?php print $tabs ?></div> <?php };?>
        <?php print $help ?>
        <?php print $messages ?>
        <?php print $content; ?>
        <?php print $feed_icons; ?>
			</div>
		</div>	

    <?php if (!internet_center_is_admin()) { ?>
  		<div class="right">

        <?php if ($search_box): ?>
    			<div class="right_login">
            <?php print $search_box; ?>
    			</div>
        <?php endif; ?> 

  			<div class="right_articles">
         <?php print $right ?>
  			</div>
  		</div>	
    <?php } else {?> 
  		<div class="right_admin">
         <?php print $right ?>
  		</div>	
    <?php }; ?> 

		<div class="footer">
      <?php print $footer_message ?>
      <?php print $closure ?>
		</div>
	</div>
</body>
</html>

