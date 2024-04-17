import { useEffect, useState } from 'react'
import Navbar from './components/Navbar'
import './App.css'

function App() {
  const [cards, setCards] = useState([])

  const fecthData = async ()=>{
    let a = await fetch ("https://jsonplaceholder.typicode.com/posts")
    let data = await a.json()
    setCards(data)
    console.log(data)
  }
  useEffect(() => {
    fecthData()
  },[])

  return (
    <>
    <Navbar></Navbar>
        <div className="container">
          {cards.map((card)=>{
            return <div key={card.id} className="card">
              <h1>{card.title}</h1>
              <p> {card.body} </p>
              <span> By: UserId: {card.userId} and  </span>
            </div>
          })}
        </div>
    </>
  )
}

export default App
