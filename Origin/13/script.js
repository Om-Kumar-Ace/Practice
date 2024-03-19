function CreateCard(title,cname,views,monthsold,duration,thumbnail) {
    let viewsno
    if (views> 100000){
        viewsno = views/1000 +"K"
    } 
    else if (views> 100000000){
        viewsno = views/1000000 +"M"
    } 
    else{
        viewsno = views
    }
    let html=`<div class="card">
    <div class="image">
        <img src="${thumbnail}" alt="Thumbnail img">
        <div class="capsule">${duration}</div>
    </div>
    <div class="text">
        <h1>${title}</h1>
        <p>${cname} . ${viewsno} views . ${monthsold} months ago</p>
    </div>`
document.querySelector(".container").innerHTML=html
}

CreateCard("Introduction to backend | Sigma","King","74452", "2","31:22", "https://i.ytimg.com/vi/tVzUXW6siu0/hqdefault.jpg?sqp=-oaymwEcCPYBEIoBSFXyq4qpAw4IARUAAIhCGAFwAcABBg==&rs=AOn4CLACwWOixJVrKLFindK92kYMgTcQbw")