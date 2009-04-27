$(document).ready(function() {
		$("#block-menu-menu-demo ul.menu").accordion({
			alwaysOpen: false,
			autoheight: false,
			header: 'a.head',
			clearStyle: true,
				event: 'mouseover'
		});
		$("#block-menu-menu-demo ul.menu ul.menu").accordion({
			alwaysOpen: false,
			autoheight: false,
			header: 'a.head',
			clearStyle: true,
				event: 'mouseover'
		});

		$("#block-menu-primary-links ul.menu").accordion({
			alwaysOpen: false,
			autoheight: false,
			header: 'a.head',
			clearStyle: true,
			event: 'mouseover'
		});
		$("#block-menu-primary-links ul.menu ul.menu").accordion({
			alwaysOpen: false,
			autoheight: false,
			header: 'a.head',
			clearStyle: true,
			event: 'mouseover'
		});
	});


$(function() {         
    $("div.scrollable").scrollable({
      	size:4,
      	loop:false,
	easing:"linear",
	keyboard:true,

clickable:false
    }); 
});



/*var api = $("div.scrollable").scrollable(); 
 
// perform a simple API call 
api.next(); 
 
// supply a callback function to an API call 
api.next(function() { 
    // here this- variable points to the API 
    this.prev(); 
}); */





//for auto scroll
/*$(function() {         
         
    // initialize scrollable  
    $("div.scrollable").scrollable({ 
             
        // items are auto-scrolled in 2 secnod interval 
        interval: 2000, 
         
        // when last item is encountered go back to first item 
        loop: true,  
         
        // make animation a little slower than the default 
        speed: 600, 
         
easing:"linear",

keyboard:true,

clickable:false,

        // when seek starts make items little transparent 
        onBeforeSeek: function() { 
            this.getItems().fadeTo(300, 0.2);         
        }, 
         
        // when seek ends resume items to full transparency 
        onSeek: function() { 
            this.getItems().fadeTo(300, 1); 
        } 


    });     
     
}); */



