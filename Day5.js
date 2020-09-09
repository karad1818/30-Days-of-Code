var canvas = document.querySelector("canvas");

canvas.width=window.innerWidth;
canvas.height=window.innerHeight;

var c = canvas.getContext("2d");


var mouse ={
	x:undefined,
	y:undefined
};
function CreateAnimation(x,y,dx,dy,radius,color){
	this.x = x;
	this.y = y;
	this.dx = dx;
	this.dy = dy;
	this.radius = radius;
	this.color = color;
	this.drawCircle = function(){
		c.beginPath();
		c.arc(this.x,this.y,this.radius,0,2*Math.PI,false);
		c.fillStyle = this.color;
		c.fill();
	}
	this.move = function(){
		if(this.x+this.radius > innerWidth || this.x-this.radius < 0){
			this.dx=-this.dx;
		}
		if(this.y+this.radius > innerHeight || this.y-this.radius < 0){
			this.dy=-this.dy;
		}
		this.x+=this.dx;
		this.y+=this.dy;
		//interaction

		if(Math.abs(this.x-mouse.x)<50 && Math.abs(this.y-mouse.y)<50 && this.radius < 50){
			this.radius+=1;
		}else{
			this.radius=radius;
		}

		this.drawCircle();
	}
}

var color = [
	'#303960',
	'#ea9a96',
	'#f8b24f',
	'#ff4b5c'
];
var circle = [];
for(var i=0;i<800;i++){
	var x=Math.random()*innerWidth;
	var y=Math.random()*innerHeight;
	if(x+radius>innerWidth)
		x-=radius;
	if(x<radius)
		x+=radius;
	if(y<radius)
		y+=radius;
	if(y+radius>innerHeight)
		y-=radius;
	var dx = (Math.random()-0.5)*7;
	var dy = (Math.random()-0.5)*7;
	var radius = Math.random()*7;
	var col = color[Math.floor(Math.random()*4)];
	circle.push(new CreateAnimation(x,y,dx,dy,radius,col));
}
function animate(){
	requestAnimationFrame(animate);
	c.clearRect(0,0,window.innerWidth,window.innerHeight);
	for(var i=0;i<circle.length;i++){
		circle[i].move();
	}
}
animate();

window.addEventListener("mousemove",function(event){
	mouse.x=event.x;
	mouse.y=event.y;
});
