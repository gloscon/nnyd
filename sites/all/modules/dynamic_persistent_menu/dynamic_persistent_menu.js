var overMenu;
var overStatus = 1;

$(document).ready(function()
{
  overMenu = overMenuDefault;
  //console.log("Go!");
  $(".dynamic-persistent-menu-menu-item").mouseover(
    function ()
    {
        overStatus = 1 ;

        if (overMenu)
        {
          $('#' + overMenu).hide();
        }

        overMenu = dynamic_persistent_menu_get_sub_menu(this.id);
        //console.log("Overing on " + this.id);
        //console.log("Sub menu id is " + overMenu);
        $('#' + overMenu).show();
    }
    ).mouseout(
        dynamic_persistent_menu_set_timeout
      );
      
    $(".dynamic-persistent-menu-sub-menu").mouseover(
        function()
        {
          if (dynamic_persistent_menu_get_sub_menu(overMenu) == this.id)
          {
            overStatus = 1;
          }
        }
      ).mouseout(
dynamic_persistent_menu_set_timeout
        )
});

function dynamic_persistent_menu_get_sub_menu(menu_id)
{
  return menu_id.replace('dynamic-persistent-menu-menu','dynamic-persistent-menu-sub-menu');
}

function dynamic_persistent_menu_reset()
{
  if (!overStatus)
  {
    $('#' + dynamic_persistent_menu_get_sub_menu(overMenu)).hide();
    overMenu = overMenuDefault;
    $('#' + dynamic_persistent_menu_get_sub_menu(overMenu)).show();
  }
}

function dynamic_persistent_menu_set_timeout()
{
  overStatus = 0 ;
  setTimeout( 'dynamic_persistent_menu_reset()' , subMenuTimeout );
}