// Paint a small filled circle on the canvas for each key (location) in coords (randomly placed)
function drawLocations() {
    for (let k in coords) {
        ctx.beginPath();
        let x = coords[k].x;
        let y = coords[k].y;
        ctx.arc(x, y, 10, 0, 6.3);
        ctx.fillStyle = "white";
        ctx.fill();
    }
}
let packages = []
function drawPackages(){
    
    for (let k in coords) {
        ctx.beginPath();
        let x = coords[k].x - 65;
        let y = coords[k].y + 20;
        ctx.fillStyle = "DarkSeaGreen";
        ctx.fillRect(x,y,25*5.5,15*1.5);
        ctx.fill();

        //Dette er en måde at genererer et random bogstav istedet for et tal.
        var pakke = '';
        var husnumre = 'ABCDEFGHPSZ';
        var husnumreLength = husnumre.length;
        pakke += husnumre.charAt(Math.floor(Math.random() * husnumreLength));

        //Hvis pakkes værdi har samme størrelse som k, gør vi det om! Hvis pakken ikke har samme størrelse som k,
        //får den samme værdi som k. Dette gør så huset ikke har en pakke til sig selv.
        while (pakke == k)
        {
        pakke = husnumre.charAt(Math.floor(Math.random() * husnumreLength));
        }
        packages.push({"from": k, "to": pakke})
            k = pakke;

        // tekst
        ctx.fillStyle = "black"
        ctx.textAlign = "center";       
        ctx.fillText(coords[k].Name,x+68,y+16);
        }
        return packages;
}

function textLocations(){
    for(let k in coords){
        ctx.fillStyle = "black";
        ctx.font = "15px Arial";
        ctx.textAlign = "center";
        ctx.fillText(coords[k].Name,coords[k].x,coords[k].y-20);
        ctx.fill();
    }
}

function makeWhite(){
    ctx.fillStyle = "white";
    ctx.fill();
}

// ctx.moveTo gør at vi rykker hen på n'te plads, hvor man derefter bruger ctx.lineTo for at lave linjen mellem det punkt, 
// man rykkede til og hen til det punkt, hvor man gerne vil have en streg
// vi har brug for koordinaterne, så derfor bruger vi coords.x for x-værdi og coords.y for y-værdi. 
// Vi skal bruger arrayet roads, da det er start og slutpunkt. roads[n][] n bliver i dette array række, og anden bracket bliver kolonne.
// vi bruger n til at tælle op i rækker, hvor vi skal bruger 0 i anden bracket for første koordinat, 
// hvor vi skal bruge vores anden koordinat til moveTo. Derfor bruger vi 1 i anden bracket

function drawRoads() {
    for (n in roads) {
        ctx.beginPath();
        ctx.moveTo(coords[roads[n][0]].x,coords[roads[n][0]].y);
        ctx.lineTo(coords[roads[n][1]].x,coords[roads[n][1]].y);
        ctx.stroke();
        ctx.closePath();
    }
}


// Draw robot at location 'P' where 'P' is a string
function robot(){
    //Start lokation:
    ctx.beginPath();
    let x = coords['P'].x;
    let y = coords['P'].y;
    ctx.arc(x, y, 10, 0, 6.3);
    ctx.fillStyle = "black";
    ctx.fill();

    console.log(packages)

    //Moving using roads
    for (let k = 0; k < packages.length; k++)
    {
        //Vi giver x og y funktionerne af coords
    let x = coords[packages[k].from];
    let y = coords[packages[k].to];

    //Vi prøver at bruge moveTo og lineTo til at flytte robotten
    ctx.moveTo(x[k],y[k]);
    ctx.lineTo(x[k])

    ctx.arc(x, y, 10, 0, 6.3);
    ctx.fillStyle = "black";
    ctx.fill();
    }
    console.log(packages);
}