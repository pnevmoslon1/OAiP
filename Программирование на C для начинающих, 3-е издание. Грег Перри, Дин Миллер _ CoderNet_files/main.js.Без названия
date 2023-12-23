document.addEventListener('DOMContentLoaded', function(){

    const openModalButton = document.querySelectorAll('[data-modal]');
    const modal = document.querySelector(".js-mobile-modal");

    const selectVideoButton = document.querySelector('.js-select-video');
    const selectVideoData = document.querySelector('.js-label-select');
    const videoNumber = document.querySelector('.js-number');
    const videoDuration = document.querySelector('.js-duration');
    const videoTitle = document.querySelector('.js-title');
    const video = document.querySelector('.js-video'); 
    const selectVideoButtonDesktop = document.querySelectorAll('.js-button-lesson');
    const page = document.querySelector('.js-page');

    if(selectVideoButton){
        selectVideoButton.addEventListener('change', function(){
            const selectedOption = selectVideoButton.options[selectVideoButton.selectedIndex];
            const srcValue = selectVideoButton.options[selectVideoButton.selectedIndex].getAttribute('data-link');
            videoNumber.innerHTML = selectedOption.getAttribute('data-number');
            videoDuration.innerHTML = selectedOption.getAttribute('data-duration');
            videoTitle.innerHTML = selectedOption.getAttribute('data-title');
        
            video.setAttribute('src', srcValue);
        })
    }
    
    


    const openVideoDesktop = function(button){
        button.addEventListener('click', function(e){

            for(let i = 0; i < selectVideoButtonDesktop.length; i++){
                selectVideoButtonDesktop[i].classList.remove('player__snippet--current');
            }

            button.classList.add('player__snippet--current');
            const srcValue = button.getAttribute('data-link');
            video.setAttribute('src', srcValue);
        })
    }

    for(let i = 0; i < selectVideoButtonDesktop.length; i++){
        openVideoDesktop(selectVideoButtonDesktop[i]);
    }

    const openModal = function(button){
        button.addEventListener('click', function(e){
            e.preventDefault();
            const attrValue = button.getAttribute('data-value');
            const attrModal = button.getAttribute('data-modal');

            if(attrModal === 'open'){
                page.classList.add('page--unscrollable');
                switch(attrValue) {
                    case 'menu':
                        modal.classList.add('mobile-modal--active');
                        modal.querySelector('.js-menu').classList.remove('mobile-modal__wrapper--hidden');
                        break;
                    case 'category':
                        modal.classList.add('mobile-modal--active');
                        modal.querySelector('.js-category').classList.remove('mobile-modal__wrapper--hidden');
                        break;
                    default:
                        break;
                }
            }else if(attrModal === 'close'){
                page.classList.remove('page--unscrollable');
                switch(attrValue) {
                    case 'menu':
                        modal.classList.remove('mobile-modal--active');
                        modal.querySelector('.js-menu').classList.add('mobile-modal__wrapper--hidden');
                        break;
                    case 'category':
                        modal.classList.remove('mobile-modal--active');
                        modal.querySelector('.js-category').classList.add('mobile-modal__wrapper--hidden');
                        break;
                    default:
                        break;
                }
            }
            
        })
    }

    for(let i = 0; i < openModalButton.length; i++){
        openModal(openModalButton[i]);
    }

})