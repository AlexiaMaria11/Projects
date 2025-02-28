var poze = [];
for(var i=0; i<6; i++)
    poze.push("images/dice" + (i+1) + ".png");

var randomNumber1 = Math.random() * 6;
randomNumber1 = Math.floor(randomNumber1) + 1;
document.querySelector(".img1").setAttribute("src", poze[randomNumber1 - 1]);

var randomNumber2 = Math.random() * 6;
randomNumber2 = Math.floor(randomNumber2) + 1;
document.querySelector(".img2").setAttribute("src", poze[randomNumber2 - 1]);

if(randomNumber1 > randomNumber2){
    document.querySelector("h1").innerHTML="🚩Player 1 wins!";
}else if(randomNumber1 === randomNumber2){
        document.querySelector("h1").innerHTML="Draw!";
}else     document.querySelector("h1").innerHTML="Player 2 wins!🚩";