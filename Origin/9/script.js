let random = Math.random()
let a = prompt("Enter 1st No.")
let c = prompt("Enter Operation")
let b = prompt("Enter 2nd No.")

let obj ={
    "+ ":" *",
    "/ ":" -",
    "* ":" /",
    "- ":" +",

}

if (random >0.10) {
    alert(`The result is ${eval(`${a} ${c} ${b}`)}`) 
}
else{
    c=obj[c]
    alert(`The result is ${eval(`${a} ${c} ${b}`)}`)
}