//
//  TouchBeamConstants.h
//  TouchBeamTestApp
//
//  Created by tal shahar on 11/6/14.
//  Copyright (c) 2014 tal shahar. All rights reserved.
//

static NSString* const kTbEventUserDataKey = @"user_data";
static NSString* const kTbDeepLinkKey = @"deep_link";
static NSString* const kTbInAppMessageRootKey = @"iam";
static NSString* const kTbInAppMessageInboxTriggerKey = @"inbox_trigger";
static NSString* const kTbInAppMessageId = @"iam_id";

//in app message dictionary keys
static NSString* const kTbInAppMessageImageUrl = @"image_url";
static NSString* const kTbInAppMessageTitle = @"title";
static NSString* const kTbInAppMessageSubtitle = @"sub_title";
static NSString* const kTbInAppMessageButtons = @"buttons";

//name touchbeam notification posted through NSNotificationCenter to report events with an in app message
//listen to this notification if you need to get notified in case an in app message is covering the screen or being dismissed
static NSString* const kTbIamEventNotification = @"tbIamEventNotification";

//keys for dictionary passed with this notification
static NSString* const kTbIamEvent = @"iam_event";
static NSString* const kTbIamAction = @"iam_action";
static NSString* const kTbIamDescription = @"iam_description";
static NSString* const kTbIamLaunched = @"iam_launched";
static NSString* const kTbIamExpired = @"iam_expired";
static NSString* const kTbIamClosed = @"iam_closed";
static NSString* const kTbIamDismissedCloseButton = @"dismiss";
static NSString* const kTbIamDismissedTimeout = @"time out";

//roam
