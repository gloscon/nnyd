<!--<?php print 'hi node';?>
<div <?php {
  echo 'id="block-nodeasblock-'.$node->nid.'"';
  echo ' class="block block-nodeasblock-',$node->nid,'"';
} ?>>

  <h3 class="title"><?php print $node->title ?></h3>

  <div class="content">
    <?php echo $node->teaser ?>
  </div>
  <div class="readon clear"><a href="<?php print '?q=node/'.$node->nid ?>"><?php print t('Read more123') ?></a></div>
</div>-->

<div class="nodeblocktext">

<div <?php {
  //echo 'id="block-nodeasblock-'.$node->nid.'"';
//  echo ' class="block block-nodeasblock-',$node->nid,'"';
} ?>>


 <!-- <h3 class="title"><?php print $node->title ?></h3>-->

  <div class="content"><span class="nav" />
    <?php echo $node->teaser ?>
  </div>
  <div class="readon clear"><a href="<?php print 'node/'.$node->nid ?>"><?php print t('more...') ?></a></div>
</div>

</div><!-- nodeblocktext ends-->
