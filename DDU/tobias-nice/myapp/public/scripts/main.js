// Roads and coords objects are expected to be loaded
const ctx = document.querySelector("#town").getContext("2d");

drawRoads();
drawLocations();
textLocations();
makeWhite();
drawPackages();
build_connections();
robot();
