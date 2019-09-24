function mouseIn() {
    $('.img').addClass('show');
  }
  
  function mouseOut() {
    $('.img').removeClass('show');
  }
  
  $('.hover-me').hover(mouseIn, mouseOut);