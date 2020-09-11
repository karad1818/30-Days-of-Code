var canvas = document.querySelector("canvas");

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

var c = canvas.getContext("2d");
var gravity = 1;
var mouse = {
	x:undefined,
	y:undefined
};
var color = [
	"#24a19c",
	"#6ebfb5",
	"#ffc7c7",
	"#ff5f40"
];

function getRandom(limit){
	return (Math.floor(Math.random()*limit*10))%limit;
}

function createCircle(x,y,dy,radius,color){
	this.x = x;
	this.y = y;
	this.radius = radius;
	this.color = color;
	this.dy = dy;
	this.draw = function(){
		c.beginPath();
		c.arc(this.x,this.y,this.radius,0,Math.PI*2,false);
		c.fillStyle = this.color;
		c.strokeStyle = 'black';
		c.stroke();
		c.fill();
	};
	this.update = function(){
		
		if(this.y+this.radius+this.dy > canvas.height){
			this.dy=-this.dy*0.95;
		}else{
			this.dy += gravity;
		}
		this.y+=this.dy;
		this.draw();
	};

}
var circle = [];
function init(){
	for(var i=0;i<200;i++){
		var r=Math.max(getRandom(40),20);
		var w=canvas.height - r;
	 	circle[i] = new createCircle(Math.max(getRandom(canvas.width),r),getRandom(w),getRandom(10),r,color[getRandom(4)]);
	}
}
init();

function animate(){
	requestAnimationFrame(animate);
	c.clearRect(0,0,canvas.width,canvas.height);
	for(var i=0;i<circle.length;i++)
		circle[i].update();
}
animate();
