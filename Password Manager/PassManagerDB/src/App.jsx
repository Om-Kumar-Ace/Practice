import { useState } from 'react'

import './App.css'
import Navbar from './components/Navbar'
import Manager from './components/Manager'
import Footer from './components/Footer'

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      <div>
        <Navbar />
        <div className="min-h-[84.8vh]">

          <Manager />
        </div>
        <Footer />
      </div>
    </>
  )
}

export default App
