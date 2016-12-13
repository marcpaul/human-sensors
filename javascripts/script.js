$(document).ready(function() {
    $("area").qtip({ // Grab all elements with a non-blank data-tooltip attr.
    content: {
        text: function(event, api) {
            // Retrieve content from custom attribute of the $('.selector') elements.
            return $(this).attr("data-tooltip-content");
        },
        title: function(event, api) {
            // Retrieve content from custom attribute of the $('.selector') elements.
            return $(this).attr("data-tooltip-title");
        }
    },
    style: {
        classes: "qtip-dark big-fonts",
        tip: {
            corner: false
        }
    },
    position: {
        target: 'mouse',
        adjust: {
            x: 30
        }
    }
});


});
