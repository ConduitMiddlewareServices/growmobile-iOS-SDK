//
//  GMEConstants.h
//
// Created by Growmobile
//  Copyright (c) 2016 Growmobile. All rights reserved.
//

static NSString* const kGmeEventUserDataKey = @"user_data";
static NSString* const kGmeDeepLinkKey = @"deep_link";
static NSString* const kGmeApsKey = @"aps";
static NSString* const kGmeAlertKey = @"alert";
static NSString* const kGmeBodyKey = @"body";
static NSString* const kGmeMessageKey = @"message";
static NSString* const kGmeTitleKey = @"title";
static NSString* const kGmeCampaignIdKey = @"campaign_id";
static NSString* const kGmeInAppMessageRootKey = @"iam";
static NSString* const kGmeInAppMessageInboxTriggerKey = @"inbox_trigger";
static NSString* const kGmeInAppMessageId = @"iam_id";
static NSString* const kGmeUserDataSuccessKey = @"GmeUserDataSuccessKey";
static NSString* const kGmeUserDataMessageKey = @"GmeUserDataMessageKey";

//in app message dictionary keys
static NSString* const kGmeInAppMessageImageUrl = @"image_url";
static NSString* const kGmeInAppMessageTitle = @"title";
static NSString* const kGmeInAppMessageSubtitle = @"sub_title";
static NSString* const kGmeInAppMessageButtons = @"buttons";

//name GME notification posted through NSNotificationCenter to report events with an in app message
//listen to this notification if you need to get notified in case an in app message is covering the screen or being dismissed
static NSString* const kGmeIamEventNotification = @"GmeIamEventNotification";

//keys for dictionary passed with this notification
static NSString* const kGmeIamEvent = @"iam_event";
static NSString* const kGmeIamAction = @"iam_action";
static NSString* const kGmeIamDescription = @"iam_description";
static NSString* const kGmeIamLaunched = @"iam_launched";
static NSString* const kGmeIamExpired = @"iam_expired";
static NSString* const kGmeIamClosed = @"iam_closed";
static NSString* const kGmeIamDismissedCloseButton = @"dismiss";
static NSString* const kGmeIamDismissedTimeout = @"time out";

//return type enum for adsmart
static NSString* const kGmeReturnKey = @"GmeAdSmartReturnKey";
static NSString* const kGmeTypeKey = @"GmeAdSmartTypeKey";
static NSString* const kGmeErrorMessageKey = @"GmeAdSmartErrorMessageKey";

typedef enum : NSUInteger {
    GME_adSmartNone, //this is not a good time to show an add
    GME_adSmartDisabled, //GME AdSmart was remotely disabled by customer
    GME_adSmartNotSupported, //either placement or ad type is not supported or not recognized by GME SDK. Check for the reason in GmeAdSmartMessageKey
    GME_adSmartShow //show the ad type that appears in GmeAdSmartTypeKey
} GME_adSmartReturnType;
