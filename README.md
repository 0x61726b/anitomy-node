#Anitomy Node

anitomy-node ports the anime file name parser [Anitomy](https://github.com/erengy/anitomy) to Node in case someday you need to parse anime file names in Node ever (unlikely).

Sample output from chrome console:

![](http://i.imgur.com/1AhBg0f.png)



#Usage
You can simply require the library and create an object off of it.

To use anitomy-node in Electron,since Electron has its own Node binary, you have to [compile against it](https://github.com/electron/electron/blob/master/docs/tutorial/using-native-node-modules.md).

```node-gyp rebuild --target=0.36.2 --arch=x64 --dist-url=https://atom.io/download/atom-shell```

otherwise, just type ```npm install```.


An example usage of the module:

```

var AnitomyModule = require('anitomy-node');
var AnitomyNode = new AnitomyModule();

var ParseResult = AnitomyNode.Parse("[Coalgirls]_Yosuga_no_Sora_04_(1280x720_Blu-Ray_FLAC)_[7CB1CD3F]");

console.log(ParseResult.AnimeTitle); //Yosuga no Sora
console.log(ParseResult.EpisodeNumber); // 04
console.log(ParseResult.Resolution); //1280x720
console.log(ParseResult.AudioTerm); //FLAC
console.log(ParseResult.FileChecksum); //7CB1CD3F

//ParseResult has the following structure
/*
[AnimeSeason,
AnimeSeasonPrefix,
AnimeTitle,
AnimeType,
AnimeYear,

AudioTerm,
DeviceCompatibility,

EpisodeNumber,
EpisodeNumberAlt,
EpisodePrefix,
EpisodeTitle,

FileChecksum,
FileExtension,
FileName,

ReleaseGroup,
ReleaseInfo,
ReleaseVersion,

Source,
Subtitles,
Resolution,

VideoTerm,
VolumeNumber,
VolumePrefix
]

*/

```

#Tests

Install ```npm i jasmine-node``` then run ```npm test```.

![](http://i.imgur.com/ujWkXm5.png)


#Installing

``` npm install anitomy-node ```

You'll need

- MSVC for Windows (Visual Studio 2013)
- node-gyp
- NaN

or just type ```npm install``` and NPM will build it for you.
