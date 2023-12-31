const { createServer } = require('http')
const { parse } = require('url')
const next = require('next')

const mqtt = require('./mqtt')
mqtt.listen();

const dev = process.env.NODE_ENV !== 'production'
const app = next({ dev })
const handle = app.getRequestHandler()
const PORT = process.env.PORT || 3000;
const HOST = '0.0.0.0';

app.prepare().then(() => {
  createServer((req, res) => {
    const parsedUrl = parse(req.url, true)
    const { pathname, query } = parsedUrl
    handle(req, res, parsedUrl)
  }).listen(PORT, HOST, () => {
      console.log(`> Ready on http://localhost:${ PORT }`);
  });
})
