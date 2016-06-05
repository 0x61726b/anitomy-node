if( typeof AnitomyModule === 'undefined' ) {
  var AnitomyModule = require('../.');
}

describe('AnitomyParse', function(){
  var Anitomy = new AnitomyModule();

  var ParseResult = Anitomy.Parse("[Coalgirls]_Yosuga_no_Sora_04_(1280x720_Blu-Ray_FLAC)_[7CB1CD3F]");


  it('Anime File Parse', function(){
    expect(ParseResult.AnimeTitle).toBe("Yosuga no Sora");
    expect(ParseResult.ReleaseGroup).toBe("Coalgirls");
    expect(ParseResult.EpisodeNumber).toBe("04");
    expect(ParseResult.Resolution).toBe("1280x720");
    expect(ParseResult.AudioTerm).toBe("FLAC");
    expect(ParseResult.FileChecksum).toBe("7CB1CD3F");
    expect(ParseResult.Source).toBe("Blu-Ray");
    expect(ParseResult.FileName).toBe("[Coalgirls]_Yosuga_no_Sora_04_(1280x720_Blu-Ray_FLAC)_[7CB1CD3F]");

  });
})
