/* define Object */
/* object literal syntax */
let employee = {
	salary:20000,
	over_time:10,
	rate:30,
	location:{
		x:10,
		y:10
	},
	get_salary : function(){
		return this.over_time*this.rate + this.salary;
	}
};

//Access
employee.get_salary();

//Factory function

function createCircle(salary){
	return {
		salary, //salary:salary -->in ES6 salary only
		draw:function(){
			console.log("Hello");
		}
	};
}

const circle = createCircle(1);

//constructor Function
//first letter Capital 
function Create(salary){
	this.salary=salary;
	this.draw = function(){
		console.log("hello");
	};
}

const c = new Create(1);

//every object has a constructor property

//e.g. new Number(),new String()

//object in js are dynamic
//we can add some property after declaration

c.added = 2; //c['added']=2

//for deleting
delete c.added;

//Enumerating in object

for (let i in Create){

}

//For abstraction
function CCreate(salary){
	let power = 200; //use let so that it won't be accessible from outside
	this.salary=salary*power;
	this.draw = function(){
		console.log("hello");
	};
}
