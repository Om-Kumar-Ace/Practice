
const addItem = async (item) => {
    await randomDelay();
    let div = document.createElement("div");
    div.innerHTML = item;
    document.body.append(div)
}

const randomDelay = () => {
    return new Promise((resolve, reject) => {
        timeout = 1 + 6 * Math.random();
        setTimeout(() => {
            resolve()
        }, timeout * 1000);
    })
}

let text = [ "   Initializing Hacking...",
 "   Readingyour Files...",
 "   Password files Detectd...",
 "   Sending all passwords and ersonal files to server...",
 "   Cleaning up..." ]

 for (const item of text) {
    addItem(text)
 }

