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
        <div className="bg-violet-50 bg-[linear-gradient(to_right,#8080800a_1px,transparent_1px),linear-gradient(to_bottom,#8080800a_1px,transparent_1px)] bg-[size:44px_24px] h-85vh">

          <Manager />
        </div>
        <Footer />
      </div>
    </>
  )
}

export default App
