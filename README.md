# Testa

TODO: General info

# Building

Run following commands in terminal
```
$ qmake
$ make
```

# Usage

Testa connects (by default) to ```ws://localhost:12345```.
Testa accepts _Actions_ in following format:
```js
{
  "type": "object",
  "properties": {
    "action": {
      "type": "string"
    },
    "parameters": {
      "type": "object",
      "properties": {}
    }
  },
  "required": [
    "action",
    "parameters"
  ]
}
```

It can perform following _Actions_:

## Load URL


```js
{
  "action": "loadUrl",
  "parameters": {
    "url": "http://www.ysoft.com"
  }
}
```

## Show notification


```js
{
  "action": "showNotification",
  "parameters": {
    "title": "Notification title",
    "message": "Notification message"
  }
}
```

## Set progress (currently only Mac OS X)


```js
{
  "action": "setProgress",
  "parameters": {
    "value": 0.5
  }
}
```
