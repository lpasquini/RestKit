//
//  OTRestClient.h
//  gateguru
//
//  Created by Blake Watters on 7/28/09.
//  Copyright 2009 Objective 3. All rights reserved.
//

#import "OTRestRequest.h"
#import "OTRestParams.h"
#import "OTRestResponse.h"
#import "NSDictionary+OTRestRequestSerialization.h"
#import "Element+OTRestAdditions.h"
#import "OTRestModelMapper.h"

@interface OTRestClient : NSObject {
	NSString* _baseURL;
	NSString* _username;
	NSString* _password;
	NSMutableDictionary* _HTTPHeaders;
	OTRestModelMapper* _mapper;
}

/**
 * The base URL all resources are nested underneath
 */
@property(nonatomic, retain) NSString* baseURL;

/**
 * The username to use for authentication via HTTP AUTH
 */
@property(nonatomic, retain) NSString* username;

/**
 * The password to use for authentication via HTTP AUTH
 */
@property(nonatomic, retain) NSString* password;

/**
 * A dictionary of headers to be sent with each request
 */
@property(nonatomic, readonly) NSDictionary* HTTPHeaders;

/**
 * The model mapper for this client
 */
@property(nonatomic, readonly) OTRestModelMapper* mapper;

/**
 * Return the configured singleton instance of the Rest client
 */
+ (OTRestClient*)client;

/**
 * Set the shared singleton issue of the Rest client
 */
+ (void)setClient:(OTRestClient*)client;

/**
 * Return a Rest client scoped to a particular base URL. If the singleton client is nil, the return client is set as the singleton
 */
+ (OTRestClient*)clientWithBaseURL:(NSString*)baseURL;

/**
 * Return a Rest client scoped to a particular base URL with a set of HTTP AUTH credentials. If the singleton client is nil, the return client is set as the singleton
 */
+ (OTRestClient*)clientWithBaseURL:(NSString*)baseURL username:(NSString*)username password:(NSString*)password;

/**
 * Fetch a resource via an HTTP GET and invoke a callback with the resulting payload
 */
- (OTRestRequest*)get:(NSString*)resourcePath delegate:(id)delegate callback:(SEL)callback;

/**
 * Create a resource via an HTTP POST with a set of form parameters and invoke a callback with the resulting payload
 */
- (OTRestRequest*)post:(NSString*)resourcePath params:(NSObject<OTRestRequestSerializable>*)params delegate:(id)delegate callback:(SEL)callback;

/**
 * Update a resource via an HTTP PUT and invoke a callback with the resulting payload
 */
- (OTRestRequest*)put:(NSString*)resourcePath params:(NSObject<OTRestRequestSerializable>*)params delegate:(id)delegate callback:(SEL)callback;

/**
 * Destroy a resource via an HTTP DELETE and invoke a callback with the resulting payload
 */
- (OTRestRequest*)delete:(NSString*)resourcePath delegate:(id)delegate callback:(SEL)callback;

/**
 * Adds an HTTP header to each request dispatched through the Rest client
 */
- (void)setValue:(NSString*)value forHTTPHeaderField:(NSString*)header;

/**
 * Fetch a resource via an HTTP GET and invoke a callback with the model for the resulting payload
 */
- (OTRestRequest*)getModel:(NSString*)resourcePath delegate:(id)delegate callback:(SEL)callback;

/**
 * Fetch a resource via an HTTP GET and invoke a callback with the model for the resulting payload
 */
- (OTRestRequest*)getModels:(NSString*)resourcePath delegate:(id)delegate callback:(SEL)callback;

/**
 * Register a model mapping from a domain model class to an XML element name
 */
- (void)registerModel:(Class)class forElementNamed:(NSString*)elementName;

@end