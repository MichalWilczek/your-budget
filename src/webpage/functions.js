function changePage() {
	
}

function addSelectOption(selectID) {
	var list = $("#selectList");
	$.each(items, function(index, item) {
	  list.append(new Option(item.text, item.value));
	});
}