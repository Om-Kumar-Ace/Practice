import Image from "next/image";

export default function Home() {
  return (
    <>
      <div className="flex justify-center flex-col text-white h-[40vh] items-center gap-4">
        <div className="font-bold text-5xl flex gap-2 justify-center items-center " >Buy me a Credit<span><img src="/coin.gif" width={50} alt="" /></span> </div>
        <p className="text-center">Big P-A wibsite to fund project with big picture in mind.  Get funded by your fans and followers .Start Now !
        </p>
        <div className="gap-4">
          <button type="button" class="text-white bg-gradient-to-br from-purple-600 to-blue-500 hover:bg-gradient-to-bl focus:ring-4 focus:outline-none focus:ring-blue-300 dark:focus:ring-blue-800 font-medium rounded-lg text-sm px-5 py-2.5 text-center me-2 mb-2">Start Here</button>
          <button type="button" class="text-white bg-gradient-to-br from-purple-600 to-blue-500 hover:bg-gradient-to-bl focus:ring-4 focus:outline-none focus:ring-blue-300 dark:focus:ring-blue-800 font-medium rounded-lg text-sm px-5 py-2.5 text-center me-2 mb-2">Read More</button> </div>
      </div>
      <div className="bg-white h-1 opacity-10"></div>
      <div className="text-white container mx-auto pb-32 pt-14">
        <h2 className="text-3xl font-bold text-center mb-14">Your fans can buy you a credit</h2>
        <div className="flex gap-5 justify-around">
          <div className="item space-y-3 flex flex-col justify-center items-center">
            <img className="bg-slate-400 rounded-full p-2" width={80} height={80} src="/person.png" alt="" />
            <p className="font-bold">Fund Yourself</p>
            <p className="text-center">Your fans are available for you to help you</p>
          </div>
          <div className="item space-y-3  flex flex-col justify-center items-center">
            <img className="bg-slate-400 rounded-full p-2" width={80} height={80} src="/Coin1.gif" alt="" />
            <p className="font-bold">Fans want to help</p>
            <p className="text-center">Your fans are available for you to help you</p>
          </div>
          <div className="item space-y-3  flex flex-col justify-center items-center">
            <img className="bg-slate-400 rounded-full p-2" width={80} height={80} src="/Group.gif" alt="" />
            <p className="font-bold">Fans want to help</p>
            <p className="text-center">Your fans are available for you to help you</p>
          </div>
        </div>
      </div>
      <div className="bg-white h-1 opacity-10"></div>
      <div className="text-white container mx-auto pb-32 pt-14 flex flex-col items-center justify-center">
        <h2 className="text-3xl font-bold text-center mb-14">Learn more about us !</h2>
        <div className="flex gap-5 justify-around">
          <iframe width="560" height="315" src="https://www.youtube.com/embed/zQGQLEE1nQs?si=BaoYFlmvMqTm5Oku" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

        </div>
      </div>
    </>
  );
}
