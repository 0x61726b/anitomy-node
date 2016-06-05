//----------------------------------------------------------------------------
//Chiika
//
//This program is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 2 of the License, or
//(at your option) any later version.
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//You should have received a copy of the GNU General Public License along
//with this program; if not, write to the Free Software Foundation, Inc.,
//51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.*/
//----------------------------------------------------------------------------
#include "AnitomyNode.h"
#include <iostream>
//----------------------------------------------------------------------------

Nan::Persistent<v8::Function> AnitomyNode::AnitomyNode::constructor;
AnitomyNode::CallbackMap g_CallbackMap;

using v8::Function;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Null;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Handle;
using v8::ObjectTemplate;
using v8::Context;
using v8::Persistent;

namespace AnitomyNode
{
	AnitomyNode::AnitomyNode()
	{
	}

	AnitomyNode::~AnitomyNode()
	{
	}

	void AnitomyNode::Init(Nan::ADDON_REGISTER_FUNCTION_ARGS_TYPE target)
	{
		v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
		tpl->SetClassName(Nan::New("Root").ToLocalChecked());
		tpl->InstanceTemplate()->SetInternalFieldCount(1);

		v8::Local<v8::ObjectTemplate> inst = tpl->InstanceTemplate();

		Nan::SetPrototypeMethod(tpl,"Parse",AnitomyNode::Parse);

		constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
		Nan::Set(target,Nan::New("Root").ToLocalChecked(),Nan::GetFunction(tpl).ToLocalChecked());
	}

#define LAZY_WIDE_CONVERSION(x) std::string(x.begin(),x.end())

	NAN_METHOD(AnitomyNode::Parse)
	{
		PersistentValue arg1;
		arg1.Reset(info[0].As<Value>());

		v8::Isolate* isolate = info.GetIsolate();

		std::string param = std::string(*v8::String::Utf8Value(arg1.Get(isolate)));;
		std::wstring input = std::wstring(param.begin(),param.end());

		anitomy::Anitomy anitomy;
		anitomy.Parse(input);

		anitomy::Elements& elements = anitomy.elements();

		/*for(anitomy::element_iterator_t It = elements.begin(); It != elements.end(); ++It)
		{
		std::wcout << It->first << " " << It->second << std::endl;
		}*/

		std::string animeSeason = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementAnimeSeason));
		std::string animeSeasonPrefix = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementAnimeSeasonPrefix));
		std::string animeTitle = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementAnimeTitle));
		std::string animeType = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementAnimeType));
		std::string animeYear = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementAnimeYear));
		std::string audioTerm = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementAudioTerm));
		std::string deviceComp = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementDeviceCompatibility));
		std::string episodeNumber = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementEpisodeNumber));
		std::string episodeNumberAlt = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementEpisodeNumberAlt));
		std::string episodePrefix = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementEpisodePrefix));
		std::string episodeTitle = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementEpisodeTitle));
		std::string fileChecksum = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementFileChecksum));
		std::string fileExtension = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementFileExtension));
		std::string fileName = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementFileName));
		std::string releaseGroup = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementReleaseGroup));
		std::string releaseInfo = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementReleaseInformation));
		std::string releaseVersion = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementReleaseVersion));
		std::string source = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementSource));
		std::string subtitles = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementSubtitles));
		std::string resolution = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementVideoResolution));
		std::string videoTerm = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementVideoTerm));
		std::string volumeNumber = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementVolumeNumber));
		std::string volumePrefix = LAZY_WIDE_CONVERSION(elements.get(anitomy::kElementVolumePrefix));

		Local<Object> returnVal = Nan::New<v8::Object>();

		Nan::Set(returnVal,Nan::New("AnimeSeason").ToLocalChecked(),Nan::New(animeSeason).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("AnimeSeasonPrefix").ToLocalChecked(),Nan::New(animeSeasonPrefix).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("AnimeTitle").ToLocalChecked(),Nan::New(animeTitle).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("AnimeType").ToLocalChecked(),Nan::New(animeType).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("AnimeYear").ToLocalChecked(),Nan::New(animeYear).ToLocalChecked());

		Nan::Set(returnVal,Nan::New("AudioTerm").ToLocalChecked(),Nan::New(audioTerm).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("DeviceCompatibility").ToLocalChecked(),Nan::New(deviceComp).ToLocalChecked());

		Nan::Set(returnVal,Nan::New("EpisodeNumber").ToLocalChecked(),Nan::New(episodeNumber).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("EpisodeNumberAlt").ToLocalChecked(),Nan::New(episodeNumberAlt).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("EpisodePrefix").ToLocalChecked(),Nan::New(episodePrefix).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("EpisodeTitle").ToLocalChecked(),Nan::New(episodeTitle).ToLocalChecked());

		Nan::Set(returnVal,Nan::New("FileChecksum").ToLocalChecked(),Nan::New(fileChecksum).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("FileExtension").ToLocalChecked(),Nan::New(fileExtension).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("FileName").ToLocalChecked(),Nan::New(fileName).ToLocalChecked());

		Nan::Set(returnVal,Nan::New("ReleaseGroup").ToLocalChecked(),Nan::New(releaseGroup).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("ReleaseInfo").ToLocalChecked(),Nan::New(releaseInfo).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("ReleaseVersion").ToLocalChecked(),Nan::New(releaseVersion).ToLocalChecked());

		Nan::Set(returnVal,Nan::New("Source").ToLocalChecked(),Nan::New(source).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("Subtitles").ToLocalChecked(),Nan::New(subtitles).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("Resolution").ToLocalChecked(),Nan::New(resolution).ToLocalChecked());

		Nan::Set(returnVal,Nan::New("VideoTerm").ToLocalChecked(),Nan::New(videoTerm).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("VolumeNumber").ToLocalChecked(),Nan::New(volumeNumber).ToLocalChecked());
		Nan::Set(returnVal,Nan::New("VolumePrefix").ToLocalChecked(),Nan::New(volumePrefix).ToLocalChecked());


		info.GetReturnValue().Set(returnVal);

	}


	NAN_METHOD(AnitomyNode::New)
	{
		if(info.IsConstructCall())
		{
			v8::Isolate* isolate = info.GetIsolate();
			AnitomyNode *obj = new AnitomyNode;
			obj->Wrap(info.This());


			info.GetReturnValue().Set(info.This());
		}
		else
		{
			const int argc = 1;
			v8::Local<v8::Value> argv[argc] ={info[0]};
			v8::Local<v8::Function> cons = Nan::New(constructor);
			info.GetReturnValue().Set(cons->NewInstance(argc,argv));
		}
	}
}
