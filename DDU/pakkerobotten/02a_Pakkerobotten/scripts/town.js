// Build connection object, each key (location) should contain an array of all connected locations
function build_connections() {
    let connections = {}
    for(let k in coords)
    {
        console.log("Coords: " + k)
        connections[k]=[]
        for(n in roads){
            if(roads[n][0] == k){
                console.log(roads[n][1]);
                connections[k].push(roads[n][1])
            }
            else if(roads[n][1] == k){
                connections[k].push(roads[n][1])
                console.log(roads[n][0]);} 
        }
    }
    return connections
} 
// State object template for the town
const state = {
    init(robot_loc, packages) {
        this.robot_loc = robot_loc;
        this.packages = packages;
    },

    move(to) {}
};

const connections = build_connections();
console.log();
// Output: Array(3) [ "B", "C", "P" ]