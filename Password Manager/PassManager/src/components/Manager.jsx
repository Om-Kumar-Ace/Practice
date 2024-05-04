import React from 'react'
import { useRef } from 'react';

const Manager = () => {
    const ref = useRef()
    const showPassword =() => {
        alert("Show the password");
        if (ref.current.src.includes("icons/eyecross.png")) {
            ref.current.src = "icons/eye.png"
        }
        else{
        ref.current.src = "icons/eyecross.png"
        }
    }
    return (
        <div>
            <div className="absolute top-0 -z-10 h-full w-full bg-white">
                <div className="absolute bottom-auto left-auto right-0 top-0 h-[500px] w-[500px] -translate-x-[30%] translate-y-[20%] rounded-full bg-[rgba(173,109,244,0.5)] opacity-50 blur-[80px]">

                </div>
            </div>
            <div className="  max-w-4xl mycontainer">
                <h1 className='text-4xl text font-bold text-center'><span className='text-violet-500'> &lt;</span>

                    <span>Pass</span><span className='text-violet-500'>Manager/&gt;</span></h1>
                <p className='text-violet-900 text-center text-lg'>Your Password At Your Risk</p>
                <div className=" flex flex-col p-4 text-black gap-8 items-center">
                    <input placeholder='Enter URL' className='rounded-full border border-violet-500 w-full text-black px-4 py-1' type="text" name='' id='' />
                    <div className="flex w-full justify-between gap-8">
                        <input placeholder='Enter Username' className='rounded-full border border-violet-500 w-full px-4 py-1' type="text" name='' id='' />
                        <div className="relative">
                            <input placeholder='Enter Password ' className='rounded-full border border-violet-500 w-full px-4 py-1' type="text" name='' id=''  />
                            <span className='absolute right-[3px] top-[4px] cursor-pointer 'onClick={showPassword} >
                                <img  ref={ref} className='p-1' width={26} src="icons/eye.png" alt="eye" />
                            </span>
                        </div>
                    </div>
                    <button className='flex justify-center items-center gap-2 bg-violet-400 hover:bg-violet-300 rounded-full px-8 py-1 w-fit border border-violet-900'>
                        <lord-icon
                            src="https://cdn.lordicon.com/jgnvfzqg.json"
                            trigger="hover" >
                        </lord-icon>Save
                    </button>
                </div>

            </div>
        </div>
    )
}

export default Manager
