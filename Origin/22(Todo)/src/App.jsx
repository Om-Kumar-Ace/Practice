import { useState } from 'react'

import Navbar from './components/Navbar'

function App() {
  

  return (
    <>
    <Navbar/>
        <div className="mx-3 md:container md:mx-auto my-5 rounded-xl p-5 bg-violet-100 min-h-[80vh] md:w-[35%]">
        <h1 className='font-bold text-center text-3xl'>iTodo - Your task Your list</h1>
          <div className="addTodo my-5 flex flex-col gap-4">
          <h2 className='text-2xl font-bold'>Add a Todo</h2>
          <div className="flex">
            
          </div>
          </div>
        </div>

    </>
  )
}

export default App
