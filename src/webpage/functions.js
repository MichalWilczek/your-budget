
var paymentOptions = ["cash", "credit card", "debit card"];
var incomeCategories = ["bank interest", "pay"]; 
var expenseCategories = [
	"appartment", "books", "children", "clothes", 
	"debts", "donation", "entertainment", "food", 
	"healthcare", "internet", "phone", "savings", 
	"training", "transport", "travel", "tv", 
	"retirement"
]; 
var otherElement = "other";

function showSections(mainLabel, options, elementID) {
	var section = '<option value="'+ mainLabel +'" disabled selected>'+ mainLabel +'</option>';
	for (i=0; i<options.length; i++) {
		section += '<option value="'+ options[i] +'">'+ options[i] +'</option>';
	}
	section += '<option value="other">other</option>';
	document.getElementById(elementID).innerHTML = section;
}

function runAddIncome() {
	showSections("category", incomeCategories, "income-category-select");
}

function runAddExpense() {
	showSections("payment option", paymentOptions, "payment-option-select");
	showSections("category", expenseCategories, "expense-category-select");
}