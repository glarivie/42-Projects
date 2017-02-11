var menu = document.getElementById('menu-nav');
var choix = document.getElementById('wp-nav');

var active = false;
choix.style.display = "none";

menu.addEventListener('click', function(e) {
    if (active == false)
    {
        menu.innerHTML = 'Naviguer <i class="fa fa-caret-down"></i>';
        choix.style.display = "block";
        active = true;
    }
    else
    {
        menu.innerHTML = 'Naviguer <i class="fa fa-caret-right"></i>';
        choix.style.display = "none";
        active = false;
    }
}, false);
