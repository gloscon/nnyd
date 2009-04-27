<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="clear-block block block-<?php print $block->module ?>">
<?php print 'mod'; ?>
<div><b class="Tspiffy"><b class="Tspiffy1"><b></b></b><b class="Tspiffy2"><b></b></b><b class="Tspiffy3"></b><b class="Tspiffy4"></b><b class="Tspiffy5"></b></b></div>
<?php if (!empty($block->subject)): ?>
  <h2><?php print $block->subject ?></h2>
<?php endif;?>

  <div class="content"><?php print $block->content ?></div>

<div><b class="spiffy"><b class="spiffy5"></b><b class="spiffy4"></b><b class="spiffy3"></b><b class="spiffy2"><b></b></b><b class="spiffy1"><b></b></b></b></div>
</div>
