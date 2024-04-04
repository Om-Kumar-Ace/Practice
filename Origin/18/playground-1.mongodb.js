use("One_Pice")

db.createCollection("Straw_Hats")

// db.Straw_Hats.insertOne({
//   "Name": "Luffy",
//   "Position": "Captain",
//   "Bounty":3000000000
// })

// db.Straw_Hats.insertMany(
//  [ {
//   "Name": "Zoro",
//   "Position": "Vice-Captain",
//   "Bounty":1111000000
// },
//   {
//   "Name": "Sanji",
//   "Position": "Chef",
//   "Bounty":100001000
// },
//   {
//   "Name": "Nami",
//   "Position": "Navigator",
//   "Bounty":491000000
// }]
// )

let a = db.Straw_Hats.find({"Name":"Zoro"})
console.log(a)

db.Straw_Hats.updateOne({"Bounty":3000000000},{$set:{"Bounty":3000000001}})
db.Straw_Hats.updateMany({"Bounty":3000000000},{$set:{"Bounty":3000000004}})

db.Straw_Hats.deleteOne({"Bounty":3000000004})