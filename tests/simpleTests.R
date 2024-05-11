
library(RApiSerialize)

data(trees)
fit <- lm(log(Girth) ~ log(Volume) + log(Height), trees)

## serialize and use R's unserialize
identical(unserialize(serializeToRaw(fit)), fit)
identical(unserialize(serializeToRaw(fit,2)), fit)
identical(unserialize(serializeToRaw(fit,3)), fit)
## serialize and use our unserialize
identical(unserializeFromRaw(serializeToRaw(fit)), fit)
identical(unserializeFromRaw(serializeToRaw(fit,2)), fit)
identical(unserializeFromRaw(serializeToRaw(fit,3)), fit)
## R's serialize and our unserialize
identical(unserializeFromRaw(serialize(fit, NULL)), fit)
## R's serialize and R's unserialize (doh)
identical(unserialize(serialize(fit, NULL)), fit)
## serialize and use our unserialize, no xdr
identical(unserializeFromRaw(serializeToRaw(fit,2,TRUE)), fit)
identical(unserializeFromRaw(serializeToRaw(fit,3,TRUE)), fit)
identical(unserializeFromRaw(serializeToRaw(fit,2,FALSE)), fit)
identical(unserializeFromRaw(serializeToRaw(fit,3,FALSE)), fit)
