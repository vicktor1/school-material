window.onload = main;

function main()
{
	const features = document.querySelector(".features");
	const company = document.querySelector(".company");


	// global memory is very fast
	const features_block = document.querySelector(".features-block");
	const company_block = document.querySelector(".company-block");

// this code polymorphic cause it execute code by feching function pointer
// for required element
	function generate_block_on_hover (element, whichblock) {
		element.addEventListener("mouseover", function () {
			const divRect = element.getBoundingClientRect();

			whichblock.style.top = `${divRect.bottom}px`;
			whichblock.style.left = `${parseInt(divRect.x)}px`;

			whichblock.style.display = "block";
		});

		element.addEventListener("mouseout", function() {
			whichblock.style.display = "none";
		})
	}


// this code look much cleaner
	generate_block_on_hover(features, features_block)
	generate_block_on_hover(company, company_block);
}
