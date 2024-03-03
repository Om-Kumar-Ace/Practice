let rand = Math.random();
let first ,second ,third;
if (rand <0.33) {
    first ="Crazy"
    second ="Engine"
    third ="Bros"
}
else if (rand <0.66 && rand >0.33) {
    first ="Amazing"
    second ="Food"
    third ="Limited"
    
}
else{
    first ="Fire"
    second ="Garments"
    third ="Hub"

}

console.log(` ${first} ${second} ${third} `)