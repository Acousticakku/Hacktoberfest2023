let arr = [{ name: "customer 1", sales: 500, location: "NY" },
{ name: "customer 1", sales: 200, location: "NJ" },
{ name: "customer 1", sales: 700, location: "NY" },
{ name: "customer 1", sales: 200, location: "ORD" },
{ name: "customer 1", sales: 300, location: "NY" }];

function reduceFun2(previousValue, currentValue, index, array) {

	if (currentValue.location === "NY") {
		//console.log(previousValue.sales);
		previousValue.sales = previousValue.sales +
			Number(currentValue.sales);
	}
	return previousValue;
}

let totalSalesInNY = arr.reduce(reduceFun2);

console.log(totalSalesInNY.sales);
