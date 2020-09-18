//number  of copy
var number;
// var input = document.querySelector("input");


var canvas = document.querySelector("canvas");
canvas.width = 400;
canvas.height = 400;

var c = canvas.getContext('2d');

function drawCircle(){
	c.beginPath();
	c.arc(canvas.width/2,canvas.height/2,199,0,2*Math.PI,false);
	c.strokeStyle = 'red';
	c.stroke();
}
function drawLine(x1,y1){
	//firstLine
	c.beginPath();
	c.moveTo(canvas.width/2,canvas.height/2);
	c.lineTo(canvas.width/2,0);
	c.strokeStyle = 'red';
	c.stroke();

	//secondLine
	c.beginPath();
	c.moveTo(canvas.width/2,canvas.height/2);
	c.lineTo(x1,y1);
	c.strokeStyle = 'red';
	c.stroke();
}


function drawPointer(x,y){
	c.beginPath();
	c.arc(x,y,5,0,2*Math.PI,false);
	c.fillStyle = 'yellow';
	c.fill();
}
var angle;
function drawCircleAndLine(){
	// drawCircle();
	number = 4;
	angle =Math.PI - (2*Math.PI)/number;
	var x=199*Math.sin(angle)+canvas.width/2;
	var y=199*Math.cos(angle)+canvas.height/2;
	drawLine(x,y);
}
canvas.addEventListener("mousemove",function(event){
	
	// c.clearRect(0,0,canvas.width,canvas.height);
	var rect = canvas.getBoundingClientRect();
	var x1 = event.x-rect.left;
	var y1 = event.y-rect.top;
	// console.log(x1 + " " + y1);
	drawCircleAndLine();
	drawPointer(x1,y1);
	drawPointer(canvas.width-x1,y1);
	drawPointer(x1,canvas.height-y1);
	drawPointer(canvas.width-x1,canvas.height-y1);
});


document.querySelector("button").addEventListener("click",function(){
	c.clearRect(0,0,canvas.width,canvas.height);
	drawCircleAndLine();
}); 


function init(){
	drawCircleAndLine();
}
init();
