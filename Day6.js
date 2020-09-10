var canvas = document.querySelector("canvas");

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

var c = canvas.getContext("2d");

//draw Circle
var x=innerWidth/2;
var y=innerHeight/2;

mouse = {
	x:undefined,
	y:undefined
};

var x1=x,y1=y;
function CreateLips(){
	c.beginPath();
	c.moveTo(x1-50,y1+70);
	c.lineTo(x1+50,y1+70);
	c.lineWidth = 10;
	c.stroke();
	c.lineWidth = 1;

}
function CreateAnimatedLips(){
	c.beginPath();
	c.ellipse(x,y+80,40,50,0,0,Math.PI*2,false);
	c.fillStyle = "#8f5500";
	c.fill();
}
function CreateCircle(x,y,radius,color){
	var ok=0;
	var dist = (mouse.x-x1) * (mouse.x-x1) + (mouse.y-y1) * (mouse.y-y1);
	if(dist <= 200*200){
		ok=1;
		CreateAnimatedLips();
	}else{
		CreateLips();
	}
	if(color == 'black' && ok==1){
		radius+=15;
	}
	c.beginPath();
	c.arc(x,y,radius,0,2*Math.PI,false);
	c.fillStyle = color;
	c.fill();
	c.strokeStyle = "#8f5500";
	c.stroke();
}

var gradient = c.createRadialGradient(x,y,170,x,y,200);
gradient.addColorStop(0,"#bdb222");
gradient.addColorStop(1,'#c27400');
function CreateEmoji(){
	CreateCircle(x,y,200,gradient);

	//first eye
	CreateCircle(x-80,y-50,50,"#b8b8b8");
	CreateCircle(x-80,y-50,5,'black');

	//second eye
	CreateCircle(x+80,y-50,50,"#b8b8b8");
	CreateCircle(x+80,y-50,5,'black');
}
//border-circle


CreateEmoji();
CreateLips();
//Create Event

document.addEventListener("mousemove",function(event){
	// console.log(event.x + " " + event.y);
	mouse.x = event.x;
	mouse.y = event.y;
	
	CreateEmoji();
});
