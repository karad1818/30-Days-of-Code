var canvas = document.querySelector("canvas");
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;
var c = canvas.getContext('2d');

var mouse = {
	x:200,
	y:300
};
function Particle(x,y,radius,color,velocity){
	this.x = x;
	this.y = y;
	this.radius = radius;
	this.color = color;
	this.velocity = velocity;
	this.draw = function(){
		c.beginPath();
		c.arc(this.x,this.y,this.radius,0,2*Math.PI,false);
		c.fillStyle = this.color;
		c.fill();
	};
	this.update =function(){
		this.draw();
		this.x += this.velocity.x;
		this.y += this.velocity.y;
	};
}

function init(){
	particles = [];
}

var colorx = [
	"#e8505b",
	"#f9d56e",
	"#14b1ab",
	"#fa26a0"
];

addEventListener("click",function(event){
	mouse.x = event.clientX;
	mouse.y = event.clientY;
	var number = 100;
	var angleInc = (Math.PI*2)/number;
	init();
	for(var i=0;i<200;i++){
		var getcolor = colorx[Math.floor(Math.random()*10)%4];
		particles.push(new Particle(mouse.x,mouse.y,2,getcolor,{
			x:Math.cos(angleInc * i)*Math.random(),
			y:Math.sin(angleInc * i)*Math.random()
		}));
	}
	animate();
});



function animate(){
	requestAnimationFrame(animate);
	c.fillStyle = 'rgba(0,0,0,0.05)';
	c.fillRect(0,0,canvas.width,canvas.height);
	for(var i=0;i<200;i++){
		particles[i].update();
	}
}
