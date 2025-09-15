//
//  objc_mmsmartstreaming.h
//  mmsmartstreamer
//
//  Created by Rupesh on 11/12/17.
//  Copyright © 2017 mediamelon. All rights reserved.
//

#ifndef objc_mmsmartstreaming_h
#define objc_mmsmartstreaming_h

#include <stdio.h>
#import <Foundation/Foundation.h>

/**
 * Advertisement playback state
 */
typedef NS_ENUM(NSInteger, MMAdState){
    /**
     * Ad is requested [initial state]]
     */
    AD_REQUEST  = 1,
    
    /**
     * Ad started playing or is unpaused
     */
    AD_PLAYING,
    
    /**
     * Ad is paused
     */
    AD_PAUSED,
    
    /**
     * Ad is skipped [terminal state]
     */
    AD_SKIPPED,
    
    /**
     * Ad completed play [terminal state]
     */
    AD_COMPLETED,
    
    /**
     * Error prevented Ad play [terminal state]
     */
    AD_ERROR,
    
    /**
     * Ad is blocked [terminal state]
     */
    AD_BLOCKED,
    
    /**
     * Based on the IAB definition of an ad impression
     */
    AD_IMPRESSION,
    
    /**
     * VPAID script signaled that it is starting
     */
    AD_STARTED,
    
    /**
     * User clicks an ad to be redirected to its landing page
     */
    AD_CLICKED,
    
    /**
     * Ad playback session resumed
     */
    AD_RESUMED,
    
    /**
     * Ad playback reached first quartile
     */
    AD_FIRST_QUARTILE,
    
    /**
     * Ad playback reached midpoint
     */
    AD_MIDPOINT,
    
    /**
     * Ad playback reached third quartile
     */
    AD_THIRD_QUARTILE,
    
    /**
    * Ad ended by quiting, going back from video screen, or by any error
    */
    AD_ENDED,
    
    /*
    Unknown state
    */
    UNKNOWN,
    
    AD_CUETIMELINEADDED,
    
    AD_CUETIMELINESTART,
    
    AD_CUETIMELINEEND
};

/**
 * Advertisement Type
 */
typedef NS_ENUM(NSInteger, MMAdType){
    /**
     * Linear Advertisement
     */
    AD_LINEAR = 1,
    /**
     * Ad type not known
     */
    AD_UNKNOWN
};

static const char* CELL_RADIO_UNKNOWN = "";
static const char* CELL_RADIO_GSM = "gsm";
static const char* CELL_RADIO_WCDMA = "wcdma";
static const char* CELL_RADIO_CDMA = "cdma";
static const char* CELL_RADIO_LTE = "lte";

static int UNKNOWN_CID = -1;
static int UNKNOWN_LAC = -1;
static int UNKNOWN_SIGNAL_STRENGTH = -1000;
static int UNKNOWN_ASU = -1;

@interface MMCellInfo:NSObject
    @property (nonatomic, strong) NSString* mCellRadio;
    @property (nonatomic, assign) NSInteger mMcc;
    @property (nonatomic, assign) NSInteger mMnc;
    @property (nonatomic, assign) NSInteger mCid;
    @property (nonatomic, assign) NSInteger mLac;
    @property (nonatomic, assign) NSInteger mAsu;
    @property (nonatomic, assign) NSInteger mTa;
    @property (nonatomic, assign) NSInteger mPsc;
    @property (nonatomic, assign) NSInteger mSignalStrength;
@end

@interface MMAdInfo:NSObject
@property (nonatomic, strong) NSString* adClient;
@property (nonatomic, strong) NSString* adId;
@property (nonatomic, strong) NSString* adCreativeId;
@property (nonatomic, assign) NSInteger adDuration;
@property (nonatomic, assign) NSInteger adPositionInPod;
@property (nonatomic, strong) NSString* adPosition;
@property (nonatomic, assign) MMAdType adType;
@property (nonatomic, strong) NSString* adCreativeType;
@property (nonatomic, strong) NSString* adServer;
@property (nonatomic, strong) NSString* adResolution;
@property (nonatomic, strong) NSString* adUrl;
@property (nonatomic, strong) NSString* adTitle;
@property (nonatomic, assign) NSInteger adPodIndex;
@property (nonatomic, assign) NSInteger adPodLendth;
@property (nonatomic, assign) BOOL isBumper;
@property (nonatomic, assign) NSInteger adBitrate;
@property (nonatomic, assign) NSInteger adScheduleTime;
@end

/**
 * Identifies the chunk/segment resource in a representation.
 * To identify the chunk in unambiguous way, provide any of following combinations:
 * <p>[Option 1] <b>trackIdx</b> and <b>sequence</b> (preferred)
 * <p>[Option 2] <b>bitrate</b> and <b>sequence</b>
 * <p>[Option 3] <b>resourceURL</b>, <b>startTime</b>, and <b>duration</b>
 * <p>[Option 4] <b>resourceURL</b>, <b>startByte</b>, and <b>endByte</b>
 * <p><p>To specify the complete entity, use Option 4 and set <b>startByte</b> to 0
 * and <b>endByte</b> to -1
 * @param [trackIdx] [Option 1] Chunk Track ID
 * @param [bitrate] [Option 2] Chunk bitrate in bits per second
 * @param [sequence] [Optiona 1] [Option 2] Chunk sequence numbe
 * @param [resourceURL] [Option 3] [Option 4] Chunk resource URL
 * @param [duration] [Option 3] Chunk duration in milliseconds
 * @param [startTime] [Option 3] Chunk starting time inmilliseconds
 * @param [startByte] [Option 4] Chunk starting byte
 * @param [endByte] [Option 4] Chunk ending byte
 * @return The MMChunkInformation object
 */
@interface MMChunkInformation:NSObject
/**
 * Chunk track id
 */
@property (nonatomic, assign) NSInteger trackIdx;

/**
 * Chunk bitrate in bits per second
 */
@property (nonatomic, assign) NSInteger bitrate;

/**
 * Chunk sequence number
 */
@property (nonatomic, assign) NSInteger sequence;

/**
 * Chunk start time in milliseconds
 */
@property (nonatomic, assign) NSInteger startTime;

/**
 * Chunk starting byte
 */
@property (nonatomic, assign) NSInteger startByte;

/**
 * Chunk ending byte
 */
@property (nonatomic, assign) NSInteger endByte;

/**
 * Chunk duration in milliseconds
 */
@property (nonatomic, assign) NSInteger duration;

/**
 * Chunk resource url
 */
@property (nonatomic, strong) NSString* resourceURL;
@end

/**
 * Specifies the device network connection type.
 */
typedef NS_ENUM(NSInteger, MMConnectionInfo){
    /**
     * Connection type is cellular (generic). If user explicitly knows the kind of connection, 2G or 3G for example, then they should use explicit enum value corresponding to that connection type.
     */
    MM_Cellular,
    
    /**
     * Connection type is 2G cellular.
     */
    MM_Cellular_2G,
    
    /**
     * Connection type is 3G cellular.
     */
    MM_Cellular_3G,
    
    /**
     * Connection type is 4G cellular.
     */
    MM_Cellular_4G,
    
    /**
     * Connection type is LTE cellular.
     */
    MM_Cellular_LTE,
    
    /**
     * Connection type is 5G cellular.
     */
    MM_Cellular_5G,
    
    /**
     * Connection non reachable.
     */
    MM_NotReachable,
    
    /**
     * Connection type is WiFi.
     */
    MM_Wifi,
    
    /**
     * Connection type is wired.
     */
    MM_WiredNetwork
};

/**
 * There may be times when the player needs to override metric values that are computed by the SDK.
 * This object lists the metrics that can be overridden.
 */
typedef NS_ENUM(NSInteger, MMOverridableMetric){
    /**
     * Time between when user requests the start of the playback session and playback starts.
     */
    Latency,
    
    /**
     * IP address of manifest server
     */
    ServerAddress,
    
    /**
     * Duration of time that the player was in the PLAYING state, excluding advertisement play time.
     */
    DurationWatched,
    
    StreamURL,
    
    DrmProtection
} ;

/**
 * MMPlayerState - State of the player
 */
typedef NS_ENUM(NSInteger, MMPlayerState){
    /**
     * Player is playing available content to the screen. Delays due to rebuffering are still considered PLAYING.
     */
    PLAYING = 1,
    /**
     * Player is paused
     */
    PAUSED,
    
    /**
     * Playback is stopped, eithre due to user request or reaching the end of the content.
     * <p><p><b>Note:</b> When the player enters the STOPPED state the current video session is terminated.
     * Re-entering the PLAYING state will result in a new session being logged for the video.
     * The most common reason for this occurring is when a video plays to the end and then the
     * user seeks back to a point earlier in the video.
     */
    STOPPED
};

/**
 * Specifies the representation information.
 */
@interface MMRepresentation:NSObject
/**
 * Representation Track ID
 */
@property (nonatomic, assign) NSInteger trackIdx;
/**
 * Representaiton bitrate in bits per second
 */
@property (nonatomic, assign) NSInteger bitrate;
/**
 * Representation width in pixels
 */
@property (nonatomic, assign) NSInteger width;
/**
 * Representation height in pixels
 */
@property (nonatomic, assign) NSInteger height;
/**
 * Codec identifier
 */
@property (nonatomic, strong) NSString* codecIdentifier;
/**
 *aCodec & vCodec can be set individually or it can be set combinely to codecIdentifier*
 *Either set combinely to codecIdentify or set aCodec & vCodec individually
 *Adding this for Custom SDK
 */
/**
 * Array of information on the segments in representation. If this information is not
 * provided, then SDK will try to have it itself (if needed)
 */
@property (nonatomic, strong) NSArray* chunkInfos;
@end

/**
 * Tells the QBR SmartStreaming engine which representations that the player can present.
 * Representations that are not in this list will not be selected by the QBR SmartStreaming engine.
 * @param isLive True if presentation is live; false if presentation is VOD
 * @param duration Content length in milliseconds. Use -1 for live
 * @param representations Array of MMRepresentation objests that are selected by the player for playback
 * @return The MMPresentationInfo object
 * @see MMRepresentation
 */
@interface MMPresentationInfo:NSObject

/**
 * True if presentation is live; false if presentation is VOD
 */
@property (nonatomic, assign) BOOL isLive;

/**
 * Content length in milliseonds. Use -1 for live.
 */
@property (nonatomic, assign) NSInteger duration;

/**
 * Array of <b>MMRepresentation</b> objects that are selected by the player for the playback.
 */
@property (nonatomic, strong) NSArray* representations;
@end

@interface MMRenditionInfo : NSObject
@property (nonatomic, assign) NSInteger bitrate;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) double frameRate;
@property (nonatomic, assign) NSString* aCodec;
@property (nonatomic, assign) NSString* vCodec;
@end

/**
 * Content/Asset Metadata
 * @param assetId Unique identifier for the asset
 * @param assetName Unique name of the asset, aka Episode Title
 * @param videoId Unique video ID
 * @param contentType Type of content (Movie / Special / Clip / Scene Epis Lifts)
 * @param drmProtection Widevine, Fairplay, Playready etc. Unknown means content is protected, For clear contents, do not set this field
 * @param episodeNumber Sequence Number of the Episode.
 * @param genre Genre of the content
 * @param season  For example - Season1,2,3 etc
 * @param seriesTitle Title of the series
 * @return The MMContentMetadata object
 */
@interface MMContentMetadata:NSObject
/**
 * assetId
 */
@property (nonatomic, strong) NSString* assetId;
/**
 * assetName
 */
@property (nonatomic, strong) NSString* assetName;
/**
 * videoId
 */
@property (nonatomic, strong) NSString* videoId;
/**
 * contentType
 */
@property (nonatomic, strong) NSString* contentType;
/**
 * drmProtection
 */
@property (nonatomic, strong) NSString* drmProtection;
/**
 * episodeNumber
 */
@property (nonatomic, strong) NSString* episodeNumber;
/**
 * genre
 */
@property (nonatomic, strong) NSString* genre;
/**
 * season
 */
@property (nonatomic, strong) NSString* season;
/**
 * seriesTitle
 */
@property (nonatomic, strong) NSString* seriesTitle;
@end

typedef NS_ENUM(NSInteger, MMQBRMode){
    QBRModeDisabled
};


/**
 * Status of the Initialization API
 */
typedef NS_ENUM(NSInteger, MMSmartStreamingInitializationStatus){
    /**
     * Initialisation not completed yet, and is in pending state
     */
    Pending,
    /**
     * Initialisation completed successfully
     */
    Success,
    /**
     * Initialisation failed
     */
    Failure,
    /**
     * Initialisation Cancelled
     */
    Cancelled
};

/**
 * Observer to look for the status of async processing of initialization of SDK
 */
@protocol MMSmartStreamingObserver
/**
 * Callback method to tell the status of the completion of the initialisation API
 *
 * @param status : status of the completion of the initialisation API
 * @param description : optional description of status accompanying the status
 * @param cmdId : Cmd ID of the completed command
 */
-(void) sessionInitializationCompletedWithStatus:(MMSmartStreamingInitializationStatus)status andDescription:(NSString*) description forCmdWithId:(NSInteger) cmdId nowtilusPermission:(BOOL) enableNowtilus;
@end

@interface MMSmartStreaming:NSObject
/**
 * Gets the SDK instance
 * @return SDK instance
 */
+ (id)getInstance;

/**
 * Gets the SDK version
 * @return SDK version (major.minor.patch)
 */
+(NSString*) getVersion;

/**
 * Gets the registration status (done via registerMMSmartStreaming)
 * @return true if the SDK has successfully registered with the registerMMSmartStreaming method;
 * otherwise returns false.
 * @see registerMMSmartStreaming
 */
+(BOOL) getRegistrationStatus;

/**
 * Registers the QBR SmartStreaming engine and performs a license verification. This API should
 * be called once when player starts. The QBR SmartStreaming engine must be successfully
 * registered before initialization.
 * <p>This is a synchronous call. Registration status can be checked at any time using the
 * getRegistrationStatus method.
 *
 * @param playerName Name of the player
 * @param customerID MediaMelon assigned customer ID
 * @param [subscriberID] Viewer's subscriber ID
 * @param [domainName] Content-owner domain name.
 *                   Some business organizations may would like to do analytics segmented
 *                   by group. For example, a Media House may have many divisions, and will like
 *                   to categorize their analysis based on division. Or a content owner has
 *                   distributed content to various resellers and would like to know the reseller
 *                   from whom the user is playing the content. In this case every reseller will
 *                   have separate application, and will configure the domain name.
 * @param [subscriberType] Viewer's subscriber Type
 * @see getRegistrationStatus
 * @see updateSubscriberID
 */
    
+(void)registerMMSmartStreamingForPlayerWithName:(NSString*) playerName forCustID:(NSString*) customerID component:(NSString*)component subsID:(NSString*)subscriberID domainName:(NSString*) domainName andSubscriberType:(NSString*) subsType withTag:(NSString*) tag hashSubID:(BOOL) hashSubID;

/**
 * After the registration, user may will like to update the subscriber ID,
 * for example - user logged off from the Video service website, and logs in again with different
 * user.
 * @param subscriberID New Subscriber ID
 * @see registerMMSmartStreaming
 */
+(void) updateSubscriberWithID:(NSString*) subscriberID andType:(NSString*)type withTag:(NSString*) tag;

/**
 * Reports the physical device characteristics to analytics. All values are optional;
 * use a NULL pointer if the value is unknown or inapplicable. Use -1 for for unknown integer
 * values.
 *
 * @param brand Device brand name.
 * @param deviceModel Device model name.
 * @param os Device operating system name.
 * @param osVersion Device operating system name.
 * @param telecomOperator Device mobile network operator.
 * @param screenWidth Device screen / display window horizontal resolution (in integer pixels).
 *                    If not known, set it to -1.
 * @param screenHeight Device screen / display window vertical resolution (in integer pixels).
 *                     If not known, set it to -1.
 */
+(void) reportDeviceInfoWithBrandName:(NSString*) brand deviceModel:(NSString*)deviceModel osName:(NSString*)os osVersion:(NSString*)osVersion telOperator:(NSString*)telOper screenWidth:(NSInteger)screenWidth screenHeight:(NSInteger)screenHeight andType:(NSString*)type;


+(void) reportExperimentNameWithExperimentName:(NSString*)experimentName;

+(void) reportSubPropertyIDWithSubPropertyId:(NSString*)subPropertyId;

+(void) reportBasePlayerInfoWithBasePlayerName:(NSString*)basePlayerName basePlayerVersion:(NSString*)basePlayerVersion;

+(void) reportAppData:(NSString*) appName  andVersion: (NSString*) appVersion;

/**
 * Reports the media player characteristics to analytics.
 * <p>Use a NULL pointer if the value is unknown or inapplicable.
 *
 * @param [brand] Brand of the player. For example - Brand could be Organisation Name.
 * @param [model] Model of the player. For example - This could be a variant of player.
 *              Say name of third party player used by organisation. Or any human readable name of
 *              the player.
 * @param [version] Version of the player.
 */
+(void) reportPlayerInfoWithBrandName:(NSString*) brand model:(NSString*) model andVersion:(NSString*) version;

/**
 * Sets Toolbox Endpoint Data
 * <p>Use a NULL pointer if the value is unknown or inapplicable.
 *
 * @param [endpointURL]
 * @param [jwtToken]
 * @param [profileID] Version of the player.
 */
+(void) setToolboxEndpoint:(NSString*) endpointURL jwtToken:(NSString*) jwtToken profileID:(NSString*) profileID cId:(NSString*) cId;

/**
 * Sets Toolbox Endpoint Data
 * <p>Use a NULL pointer if the value is unknown or inapplicable.
 *
 * @param [endpointURL]
 * @param [starzAPIKey]
 * @param [starzSessionID] Version of the player.
 */
+(void) setStarzEndpoint:(NSString*) endpointURL starzAPIKey:(NSString*) starzAPIKey starzSessionID :(NSString*) starzSessionID cId :(NSString*) cId;

/**
 * Initializes the session for playback with QBR optimization. This API should be called once for
 * every media session and is asynchronous. Its completion is indicated via callback to
 * MMSmartStreamingObserver::sessionInitializationCompleted that user may choose to ignore.
 *
 * @param mode QBR operating mode.
 * @param manifestURL URL of the media manifest
 * @param [metaURL] URL of the media metadata. If it is null, and QBR operating mode is
 *                Bitsave, CostSave, or Quality, a metadata file with manifestUrl base name will
 *                be used. If the metadata cannot be retrieved, mode will default to Disabled.
 * @param [contentMetadata] content metadata information for the session (like assetid, asset name etc.,)
 * @param observer MMSmartStreamingObserver that will receive the callback on initialization
 *                 completion.
 *
 */
-(NSInteger) initializeSessionWithMode:(MMQBRMode) mode registrationUri:(NSString*) registrationUri forManifest:(NSString*) manifestURL metaURL:(NSString*) metaURL contentMetadata:(MMContentMetadata*) contentMetadata forObserver:(id<MMSmartStreamingObserver>) observer;

/**
 * Tells the QBR SmartStreaming engine which representations that the player can present.
 * Representations that are not in this list will not be selected by the QBR SmartStreaming engine.
 * @param presentationInfo PresentationInformation specifying the representations selected by
 *                         the player for playback.
 * @see blacklistRepresentation
 */
-(void) setPresentationInformation:(MMPresentationInfo*) presentationInfo;

-(void) reportRenditionInformation:(MMRenditionInfo*) renditionInfo;

/**
 * Reports the chunk request to analytics. This method is not used when QBR optimization is
 * enabled.
 * @param chunkInfo Chunk selected by the player.
 */
-(void) reportChunkRequest:(const MMChunkInformation*) chunkInfo;

/**
 * Reports current download rate (rate at which chunk is downloaded) to analytics. This should be
 * reported for every chunk download (if possible). If this value is not available on every
 * chunk download, then last updated value with player should be reported every 2 seconds.
 *
 * @param downloadRate Download rate as measured by the player (in bits per second)
 */
-(void) reportDownloadRate:(NSInteger) downloadRate;

/**
 * Reports custom metadata, in the form of a key-value pair, to analytics.
 *
 * @param key Custom metadata key.
 * @param value Custom metadata value.
 */
-(void) reportCustomMetadataWithKey:(NSString*) key  andValue:(NSString*)value;

/**
 * Reports current playback position in media to analytics. This should be reported every two
 * seconds if possible.
 *
 * @param playbackPos Current playback position (in milliseconds).
 */
-(void) reportPlaybackPosition:(NSInteger) playbackPos;

/**
 * Reports the communications network type to analytics.
 * @param networkType : Connection Info.
 */
-(void) reportNetworkType:(MMConnectionInfo) networkType;

/**
 * Override the SmartSight-calculated metric with a specific value.
 *
 * @param metric : Metric to be overridden.
 * @param value : New metric value. Even if the value of
 *   metric is numeric, int (for example in case of latency), user
 *   is expected to provide its string representation:
 * - For Latency, the latency in seconds, with with millisecond resolution (e.g., "1.236")
 * - For ServerAddress, the name of the cdn (e.g., "PrivateCDN")
 * - For DurationWatched, the duration watched in seconds, with millisecond resolution (e.g., "137.935")
 * @see MMOverridableMetric
 */
-(void) reportMetricValueForMetric:(MMOverridableMetric) metric value:(NSString*)value;

/**
 * Reports the current player state to analytics.
 *
 * @param playerState : Player State
 */
-(void) reportPlayerState:(MMPlayerState) playerState;

/**
 * Reports the start of the buffering.
 */
-(void) reportBufferingStarted;

/**
 * Reports the completion of the buffering.
 */
-(void) reportBufferingCompleted;

/**
 * Reports the start of the ad-buffering.
 */
-(void) reportAdBufferingStarted;

/**
 * Reports the completion of the ad-buffering.
 */
-(void) reportAdBufferingCompleted;

-(void) reportViewSessionIDWithViewSessionId:(NSString*)viewSessionId;

/**
 * Reports that user initiated the playback session.
 * This should be called at different instants depending on the mode of operation of player.
 * In Auto Play Mode, should be the called when payer is fed with the manifest URL for playback
 * In non-Auto Play Mode, should be called when the user presses the play button on the
 * player
 */
-(void) reportUserInitiatedPlayback;

/**
 * Reports the ABR bitrate changes to the analytics.
 * @param prevBitrate Previous ABR bitrate in bits per second.
 * @param newBitrate New ABR bitrate in pers per second.
 */
-(void) reportABRSwitchFromBitrate:(NSInteger) prevBitrate toBitrate:(NSInteger) newBitrate;

/**
 * Reports cumulative frame loss count to analytics.
 * @param lossCnt Cumulative count of frames lost in playback session.
 */
-(void) reportFrameLoss:(NSInteger) lossCnt;

/**
 * Reports an error encountered during playback.
 * @param error Error encountered during playback session.
 * @param playbackPosMilliSec Playback position in millisec when error occurred.
 */
-(void) reportError:(NSString*) error atPosition:(NSInteger) playbackPosMilliSec;

/**
 * Reports that a seek event is complete, with the new playback starting position.
 * @param seekEndPos Playback position(in milliseconds) when seek completed. This is point from
 *                   which playback will start after the seek.
 */
-(void) reportPlayerSeekCompleted:(NSInteger) seekEndPos;

/**
 * Reports the presentation size of the stream being playbacked.
 * Call to this API is optional. It is recommended to call this API (when QBR is not integrated)
 * if user did not provided the stream resolution information as part of the setPresentationInfo API.
 */
-(void) reportPresentationSizeWithWidth:(NSInteger)width andHeight:(NSInteger) height;

-(void) reportCellularInformation:(MMCellInfo*) cellInfo;

-(void) reportLocationWithLatitude:(double)lat andLongitude:(double)lon;

/**
 * Reports the WiFi Service Set Identifier (SSID).
 * @param ssid WiFi Service Set Identifier (SSID).
 */
-(void) reportWifiSSID:(NSString*) ssid;

-(void) reportVideoQuality:(NSString*) videoQuality;

-(void) reportSDKVersion:(NSString*) reportSDKVersion;

-(void) reportDeviceID: (NSString*) deviceID;

-(void) reportDeviceMarketingName: (NSString*) deviceMarketingName;

-(void) reportDeviceCapabilities: (NSString*) deviceCapabilities;

-(void) reportVolumeChange: (NSString*) volumeStr;

-(void) reportPlaybackRateChange;

-(void) reportPlayerSeekStarted;

-(void) reportNetworkInfoWithCdn: (NSString*) cdn asn: (NSInteger) asn sourceHostName: (NSString*) sourceHostName networkType: (NSString*) networkType networkOperator: (NSString*) networkOperator;

-(void) reportStreamInfoWithStreamFormat: (NSString*) streamFormat mediaType: (NSString*) mediaType sourceType: (NSString*) sourceType;

-(void) reportEventAndDescriptionWithEvent: (NSString*) eventName description: (NSString*) description;

-(void) reportPlayerResolutionWithWidth: (NSInteger) width height: (NSInteger) height;
/**
 * Reports the WiFi signal strength. This may be useful, if someone is analyzing a
 * back playback session using smartsight's microscope feature, and wants to know if Wifi signal
 * strength is the cause fo poor performance of that session. This API is relevant if Wifi is used
 * for the playback sesssion.
 *
 * @param strength Strength of Wifi signal in %
 */
-(void) reportWifiSignalStrenthPercentage:(double) strength;

/**
 * Reports the WiFi maximum data rate.
 * @param dataRate WiFi data rate (in kbps)
 */
-(void) reportWifiDataRate:(NSInteger) dataRate;

/**
 * Reports advertisement playback state
 * @param adState State of the advertisement
 * @see MMAdState
 */
-(void) reportAdState:(MMAdState) adState;

/**
 * Reports advertisement-related information
 *
 * @param adClient Client used to play the ad, eg: VAST
 * @param adURL Tag represented by the ad.
 * @param adDuration Length of the video ad (in milliseconds).
 * @param adPosition Position of the ad in the video  playback; one of "pre", "post" or "mid"
 *                   that represents that the ad played before, after or during playback respectively.
 * @param adType Type of advertisement : {LINEAR etc}
 * @param adCreativeType Ad MIME type
 * @param adServer Ad server (ex. DoubleClick, YuMe, AdTech, Brightroll, etc.)
 * @param adResolution Advertisement video resolution
 */
-(void) reportAdInfo:(MMAdInfo *) adInfo;

/**
 * Reports current advertisement playback position
 * @param playbackPosition Current playback position in the Ad (in milliseconds)
 */
-(void) reportAdPlaybackTime:(NSInteger) playbackPosition;

/**
 * Reports error encountered during the advertisement playback
 * @param error Error encountered during advertisement playback
 * @param pos Playback position (in milliseconds) where error occurred
 */
-(void) reportAdError:(NSString*) error atPlaybackPos:(NSInteger) pos;

-(void) enableLogTrace:(BOOL)enable;

/**
 * Disables the fetching of manifests by the SDK to determine the presentation information of the content.
 * SDK will rely completely on presentation information provided as part of setPresentationInformation.
 * @param enable Disables/Enables the manifest fetch by the SDK
 * @see setPresentationInformation
 */
+(void) disableManifestsFetch:(BOOL)enable;

/**
 * Reports the Media Track Info to analytics.
 *
 * @param isSubtitleActive : is subtitle being seem
 * @param subtitleTrack description of the subtitle track
 * @param audioTrack : audio track descriptiuon
 * @param isVDSActive is Video Description Track on
 */
-(void) reportMediaTrackInfo: (BOOL) isSubtitleActive subtitleTrack: (NSString *) subtitleTrack
                  audioTrack: (NSString *) audioTrack isVDSActive: (BOOL) isVDSActive;



@end
#endif /* objc_mmsmartstreaming_h */
